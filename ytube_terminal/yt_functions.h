#ifndef YT_FUNCTIONS_H
#define YT_FUNCTIONS_H
// subscribe, list, generate-html, view-html

#include "youtube_parser.h"
#include "downloader.h"
#include <fstream>

class yt_functions
{
public:
    void subscribe(string url);
    void sub_list();
    void generate_html();
    void view_html();
    ~yt_functions();


private:
    downloader dw;
    youtube_parser yt_p;
    std::ifstream inFile;
    std::ofstream outFile;
    vector<string> downloaded_pages;
    string channelID, channelName, a_page;
    struct vid_info
    {
        string vid_id;
        string vid_title;
        time_t vid_time_unix; // unix sec
    };
    vector<vid_info> vid_vec;
    // Next three in order:
    string a = "<yt:videoId>";
    string b = "<published>";
    string c = "<media:title>";
    string abc_end = "<";
    static bool vecTimeCompare(const vid_info & one, const vid_info & two);
    const string html_pre =
        "<!DOCTYPE html>"
        "\n<html>"
        "\n<head>"
        "\n<title>Cool Stuff</title>"
        "\n<style type=\"text/css\">"
        "\nbody{background-color: #B4B4B4;}"
        "\nh2{font-size: 100%; overflow: hidden;}"
        "\nimg{width: 100%;}"
        "\na{"
        "\ntext-decoration: none;"
        "\ncolor: #333;"
        "\nfont-weight: bold;"
        "\n}"
        "\n#contain"
        "\n{"
        "\nfloat: left;"
        "\npadding-left: 2%;"
        "\npadding-right: 2%;"
        "\nwidth: 19.77%;"
        "\nbackground-color: #ddd;"
        "\npadding-top: 2%;"
        "\nmargin-left: 1%;"
        "\nmargin-bottom: 1%;"
        "\nheight: 298px;"
        "\noverflow: auto;"
        "\n}"
        "\n</style>"
        "\n</head>"
        "\n<body>\n\n";

    const string html_post =
        "\n</body>"
        "\n</html>";

    const string section_a =
        "\n<div id=\"contain\">"
        "\n<a href=\"https://www.youtube.com/embed/";
    const string section_b ="\">";
    const string section_c =
        "\n<img src=\"https://img.youtube.com/vi/";
    const string section_d =
        "/mqdefault.jpg\" >"
        "</a>"
        "\n<a href=\"https://www.youtube.com/watch?v=";
    const string section_e = "\">\n<h2>";
    const string section_f = "</h2></a>\n</div>\n\n";
    string a_id;
    string full; // html
};

#endif // YT_FUNCTIONS

