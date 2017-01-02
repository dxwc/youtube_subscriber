#ifndef DOWNLOADER
#define DOWNLOADER

#include <curl/curl.h>
#include <cstring>
#include <vector>
#include <string>

using std::string;
using std::vector;

class downloader
{
public:
    downloader();

    void check(CURLcode result);
    void add_url(string url);
    void clear_url();
    void perform_downloads(vector<string> & downloaded_pages);

    ~downloader();

protected:
    static size_t write_callback(char * ptr, size_t size, size_t nmemb, void * void_ptr);
    void collect_data(char * ptr, size_t size, size_t nmemb);
    CURL * ez_handle;
    char error_buffer[CURL_ERROR_SIZE];
    bool good_to_go = true;
    string downloaded_page;
    vector<string> string_urls;
};

#endif // DOWNLOADER

