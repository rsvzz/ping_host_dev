#include <iostream>
#include <cstdio>
#include <thread>
#include <chrono>
#include "ClientRequest.hpp"

using namespace std;

ClientRequest::ClientRequest()
{
    http = new HttpRequestCurl;
}

ClientRequest::~ClientRequest()
{
    delete http;
}

void ClientRequest::exec_request(ItemHost *host, RequestList *items)
{
    for (int i = 0; i < host->ping_rq_count; i++)
    {
        // printf("for : %s\n", host->host_name);
        std::this_thread::sleep_for(std::chrono::seconds(3)); //sleep thread
        int rq = (int)http->get_request_code(host->host_name);
        RequestItem *item = new RequestItem;
        item->id = i + 1;
        item->code = rq;
        item->messenger = "dont body";
        items->add(item);
    }

    /*
    stack<RequestItem> aux = items->get_stack_obj();
    while (!aux.empty())
    {
        //aux.top();
    }
    */
}