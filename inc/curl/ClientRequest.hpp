#pragma once
#include "HttpRequestCurl.hpp"
#include "../model/RequestList.hpp"
/// @brief Param for user
struct ItemHost{
    const char *host_name;
    int ping_rq_count;
};

/// @brief Manejador request
class ClientRequest
{
private:
    /* data */
    HttpRequestCurl *http;
public:
    ClientRequest();
    ~ClientRequest();
    void exec_request(ItemHost*,RequestList*, int);
};

