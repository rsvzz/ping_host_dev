#pragma once
#include <stack>
#include <iostream>

using namespace std;
/// @brief Item request http
struct RequestItem{
    int id;
    int code;
    const char* messenger;
};
/// @brief List RequestItem Stack
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
    stack<RequestItem> get_stack_obj();

};


