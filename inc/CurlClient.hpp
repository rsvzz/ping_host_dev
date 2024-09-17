#pragma once
#include <curl/curl.h>
class CurlClient
{
private:
    /* data */
    CURL *curl;
    CURLcode res;
public:
    CurlClient();
    ~CurlClient();
    int getNoBodyRq(const char *);
};
