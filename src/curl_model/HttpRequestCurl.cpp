#include "../../inc/curl/HttpRequestCurl.hpp"

HttpRequestCurl::HttpRequestCurl(/* args */)
{
    // curl = curl_easy_init();
}

HttpRequestCurl::~HttpRequestCurl()
{
    // delete curl;
    // curl = nullptr;
}

long HttpRequestCurl::get_request_code(const char *url)
{
    CURL *curl;
    // CURLcode res;
    curl = curl_easy_init();
    if (curl)
    {
        CURLcode res;
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
        res = curl_easy_perform(curl);
        if (res == CURLE_OK)
        {
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            curl_easy_cleanup(curl);
            return response_code;
        }
        else
        {
            curl_easy_cleanup(curl);
            return 10;
        }
    }
    curl_easy_cleanup(curl);
    return 0;
}