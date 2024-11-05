#include "../../inc/model/RequestList.hpp"
#include <stack>
#include <iostream>
using namespace std;
RequestList::RequestList()
{
    top = new stack<RequestItem>;
}

RequestList::~RequestList()
{
    delete top;
}

void RequestList::add(RequestItem *item){
    top->push(*item);
}

string RequestList::get_item_all(){
    stack<RequestItem> aux = *top;
    string str = "START CONNECTION SERVER\n";
    while(!aux.empty()){
        str += messenger_request_item(&aux.top());
        aux.pop();
    }
    return str;
}

string RequestList::messenger_request_item(RequestItem *item){
    return to_string(item->id) +" -- " + to_string(item->code) + " = " + item->messenger + "\n";
}

void RequestList::clear_all_item(){
    while (!top->empty())
    {
        top->pop();
    }
    
}
/// @brief stack obj all
/// @return copy valor
stack<RequestItem> RequestList::get_stack_obj(){
    return *top;
}