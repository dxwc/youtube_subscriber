#include "yt_functions.h"
#include <iostream>
#include <algorithm> // sort

using std::cerr;
using std::cout;

void yt_functions::subscribe(string url)
{
	if(url.find("youtube.com") == string::npos)
	{
		cerr << "invalid url\n";
		return;
	}

	dw.clear_url();
	dw.add_url(url);
	downloaded_pages.clear();
	dw.perform_downloads(downloaded_pages);

	channelName = "";
	channelID   = "";

	if(downloaded_pages.size() != 0)
	{
		a_page = downloaded_pages[0];

		channelID = yt_p.parse("data-channel-external-id=\"", "\"", a_page);

		if(url.find("/user/") != string::npos)
		{
			channelName = yt_p.parse(
					"<meta name=\"title\" content=\"",
					"\"",
					a_page);
		}
		else if(url.find("/channel/") != string::npos)
		{
			channelName = yt_p.parse(
					"<meta property=\"og:title\" content=\"",
					"\"",
					a_page);
		}
		else
		{
			channelName = yt_p.parse(
					"\"author\":\"",
					"\"",
					a_page);
		}
	}

	if(channelName == "" || channelID == "")
	{
		cerr << "Error: couldn't extract information\n";
		return;
	}
	else
	{
		inFile.open("yt_sub_list.dat");
		if(inFile.good())
		{
			string line;
			while(getline(inFile, line))
			{
				if(line == channelID)
				{
					cout << "You were already subscribed :)" << '\n';
					return;
				}
			}
		}
		inFile.close();

		outFile.open("yt_sub_list.dat", std::ios::app);
		if(outFile.good())
		{
			outFile
				<< channelID
				<< '\n'
				<< channelName
				<< "\n\n";
		}
		else
		{
			outFile.close();
			return;
		}
		outFile.close();
		cout << "You are now subscribed to: " << channelName << '\n';
	}
}

void yt_functions::sub_list()
{
	inFile.open("yt_sub_list.dat");
	cout << "\nList of channels you are subscribed to:\n\n";
	cout << "------Channel-ID--------" << '\t' << "------Channel-Name------\n";

	// a_page reused as temp
	while(getline(inFile, channelID) && getline(inFile, channelName) && getline(inFile, a_page))
	{
		cout << channelID << '\t' << channelName << '\n';
	}
	inFile.close();
}

void yt_functions::generate_html()
{
	inFile.close();
	// because calling generate, very quickly after subscribe seems to cause can not open error
	// could not find any logic error as each file opens are carefully closed. Calling close seems
	// to work fine.

	inFile.open("yt_sub_list.dat");
	if(!inFile.good())
	{
		cerr << "Error: couldn't open subscribtion yt_sub_list.dat file\n";
		inFile.close();
		return;
	}

	string url;
	dw.clear_url();
	while(getline(inFile, channelID) && getline(inFile, channelName) && getline(inFile, a_page))
	{
		url  = "https://www.youtube.com/feeds/videos.xml?channel_id=";
		url += channelID;
		dw.add_url(url);
	}
	inFile.close();
	downloaded_pages.clear();
	dw.perform_downloads(downloaded_pages);

	if(downloaded_pages.size()) { cout << "--Extracting information...\n"; }
	else { return; }

	vid_vec.clear();
	string timeStr;
	for(size_t i = 0; i < downloaded_pages.size(); ++i)
	{
		while(downloaded_pages[i].find(a.c_str()) != string::npos)
		{
			vid_info one;
			one.vid_id    = yt_p.parse(a, abc_end, downloaded_pages[i], true);
			timeStr       = yt_p.parse(b, abc_end, downloaded_pages[i], true);
			one.vid_time_unix = yt_p.timeStr_to_unix_t(timeStr);
			one.vid_title = yt_p.parse(c, abc_end, downloaded_pages[i], true);

			vid_vec.push_back(one);
		}
	}

	// sort vector by time, small to large
	std::sort(vid_vec.begin(), vid_vec.end(), vecTimeCompare);

	if(vid_vec.size() == 0) return; // assuming it's downloader's issue

	outFile.open("yt_view_subscription.html");
	if(outFile.good())
	{
		cout << "--Generating html\n";
		full = html_pre;
		a_id = "";

		size_t i_end = vid_vec.size();

		for(size_t i = 0; i < i_end; ++i)
		{
			a_id = vid_vec[i].vid_id;

			full += section_a;
			full += a_id;
			full += section_b;
			full += section_c;
			full += a_id;
			full += section_d;
			full += a_id;
			full += section_e;
			full += vid_vec[i].vid_title;
			full += section_f;
		}

		full += html_post;

		outFile << full;

	}

	outFile.close();

}

void yt_functions::view_html()
{
	inFile.open("yt_view_subscription.html");
	cout << "--Attempting to open the html on firefox\n";
	if(inFile.good() && system("firefox yt_view_subscription.html") == 0)
	{
		cout << "\nOpened a tab on firefox." << '\n';
	}
	else
	{
		if(!inFile.good())
		{
			cerr 
				<< "\nError: Couldn't open generate "
				<< "file: yt_view_subscription.html\n";
		}
		cerr << "\nError: Couldn't open on firefox." << '\n';
	}
	inFile.close();
}

bool yt_functions::vecTimeCompare(const vid_info & one, const vid_info & two)
{
	return one.vid_time_unix > two.vid_time_unix;
}

yt_functions::~yt_functions()
{
	// in case I have forgotten some cases
	inFile.close();
	outFile.close();
}
