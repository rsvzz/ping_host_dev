#include "RequestStart.hpp"
using std::string;
RequestStart::RequestStart(/* args */)
{
}

RequestStart::~RequestStart()
{
}

string RequestStart::exec_data(ItemHost* user_data, ClientRequest *http){
    RequestList list;
    http->exec_request(user_data, &list);
    string result = list.get_item_all();
    //list.clear_all_item();
    return result;

}