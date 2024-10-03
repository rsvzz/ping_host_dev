#pragma once
#include <curl/curl.h>

class HttpRequestCurl
{
private:
    /* data */
public:
    HttpRequestCurl(/* args */);
    ~HttpRequestCurl();
    long get_request_code(const char*);
};
