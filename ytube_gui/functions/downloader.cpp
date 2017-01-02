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
		// void ptr can point to any data type
		check(curl_easy_setopt(ez_handle, CURLOPT_WRITEDATA, this));
		check(curl_easy_setopt(ez_handle, CURLOPT_FORBID_REUSE, 1)); // <--
		// (change 1 to 0 to make program faster, but will hang if
		// internet connection goes from online to offline)
		// will close after each connection, bad for performance, good to
		// avoid hanging on easy_perform when internet connction goes
		// from online to offline
		check(curl_easy_setopt(ez_handle, CURLOPT_TIMEOUT, 7)); // hard limit
		// (this will need increasing for slower connections)
		// last value is seconds before timeout
		// avoids hangs if during a perform, internet connection drops

		//curl_easy_setopt(ez_handle, CURLOPT_VERBOSE, 1); 
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
	if(!good_to_go) { good_to_go = true; return; }

	size_t i_end = string_urls.size();
	for(size_t i = 0; i < i_end; ++i)
	{
		check(curl_easy_setopt(ez_handle, CURLOPT_URL, string_urls[i].c_str()));
		if(!good_to_go) { good_to_go = true; return; }

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
