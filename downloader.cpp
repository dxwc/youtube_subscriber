#include "downloader.h"

#include <iostream>

using std::cerr;
using std::cout;

downloader::downloader()
{
	ez_handle = curl_easy_init();
	if(ez_handle != NULL)
	{
		check(curl_easy_setopt(ez_handle, CURLOPT_ERRORBUFFER, error_buffer));
		check(curl_easy_setopt(ez_handle, CURLOPT_WRITEFUNCTION, this->write_callback));
		check(curl_easy_setopt(ez_handle, CURLOPT_WRITEDATA, this));
		// void ptr can point to any data type
	}
}

void downloader::check(CURLcode result)
{
	if(result != CURLE_OK)
	{
		cerr << "Error: on download operation\n";
		if(strlen(error_buffer))
		{
			cerr << "Error: " << error_buffer << '\n';
		}
		good_to_go = false;
	}
	error_buffer[0] = 0;
}

void downloader::add_url(string url)
{
	string_urls.push_back(url);
}

void downloader::clear_url()
{
	string_urls.clear();
}

void downloader::perform_downloads(vector<string> & downloaded_pages)
{
	if(!good_to_go) return;

	size_t i_end = string_urls.size();
	for(size_t i = 0; i < i_end; ++i)
	{
		if(!good_to_go) return;
		check(curl_easy_setopt(ez_handle, CURLOPT_URL, string_urls[i].c_str()));

		downloaded_page = "";
		cout << "--Download progress: " << i+1 << " of " << i_end << '\n';
		check(curl_easy_perform(ez_handle));
		downloaded_pages.push_back(downloaded_page);
	}
}

void downloader::collect_data(char * ptr, size_t size, size_t nmemb)
{
	for (size_t i = 0; i < size*nmemb; ++i)
	{
		downloaded_page += *(ptr + i);
	}
}

size_t downloader::write_callback(char * ptr, size_t size, size_t nmemb, void * void_ptr)
{
	static_cast<downloader *>(void_ptr)->collect_data(ptr, size, nmemb);

	return size*nmemb;
}

downloader::~downloader()
{
	std::cout << "\n--Closing everything\n";
	if(ez_handle != NULL)
	{
		curl_easy_cleanup(ez_handle);
	}
}
