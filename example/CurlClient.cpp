#include "../inc/CurlClient.hpp"
CurlClient::CurlClient()
{
    curl = curl_easy_init();
}

CurlClient::~CurlClient()
{
    curl_easy_cleanup(curl);
}

int CurlClient::getNoBodyRq(const char *http){
     curl_easy_setopt(curl, CURLOPT_URL, http);
     curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); //no body
   return curl_easy_perform(curl);
}
