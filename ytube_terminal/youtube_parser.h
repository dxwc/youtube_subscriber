#ifndef YOUTUBE_PARSER_H
#define YOUTUBE_PARSER_H
// parses downloaded webpage from youtube feed/video/channel url
#include <string>
#include <ctime>

using std::string;

class youtube_parser
{
public:
    string parse(
            string starts_with,
            string ends_starting,
            string & webpage,
            bool cut_page_after = false);

    time_t timeStr_to_unix_t(const string & timeStr);
};

#endif // YOUTUBE_PARSER

