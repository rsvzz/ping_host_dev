#pragma once
#include <stack>
#include <iostream>

using namespace std;

struct RequestItem{
    int id;
    int code;
    const char* messenger;
};

class RequestList
{
private:
    /* data */
    stack<RequestItem> *top;
    string messenger_request_item(RequestItem*);
public:
    RequestList(/* args */);
    ~RequestList();
    string get_item_all();
    void add(RequestItem*);
    void clear_all_item();

};


