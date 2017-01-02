#include "youtube_parser.h"


string youtube_parser::parse(
		string starts_with,
		string ends_starting,
		string & webpage,
		bool cut_page_after
		)
{
	if(starts_with.size() ==  0 || webpage.size() == 0) return "";

	int loc_a, loc_b = -1;

	loc_a = webpage.find(starts_with.c_str());
	if(loc_a == static_cast<int>(string::npos)) return "";

	loc_b = webpage.find(ends_starting.c_str(), loc_a + starts_with.size());
	if(loc_b == static_cast<int>(string::npos)) return "";

	string return_str;
	try
	{
		return_str =
			webpage.substr(
					loc_a + starts_with.size(),
					loc_b - (loc_a + starts_with.size())
					);

		if(cut_page_after == true)
		{
			webpage = webpage.substr(loc_b);
		}
	}
	catch(...) { return ""; }


	return return_str;
}

time_t youtube_parser::timeStr_to_unix_t(const string & timeStr)
{
	struct tm a_tm;

	if(strptime(timeStr.c_str(), "%Y-%m-%dT%H:%M:%S", &a_tm) == NULL)
	{
		return 0;
	}

	time_t unix_time = mktime(&a_tm);
	if(unix_time == -1) return 0;

	return unix_time;
}

