#pragma once
#include <stack>
using namespace std;

class RequestList
{
private:
    /* data */
    stack<int> *top;
public:
    RequestList(/* args */);
    ~RequestList();
    char *get_item_all();
    void add(int);
};


