#include "RequestList.hpp"
#include <stack>
RequestList::RequestList(/* args */)
{
    top = new stack<int>;
}

RequestList::~RequestList()
{
    delete top;
}

void RequestList::add(int item){
    top->push(item);
}

char *RequestList::get_item_all(){

    while(top->empty()){
        top->pop();
    }
    return "";
}