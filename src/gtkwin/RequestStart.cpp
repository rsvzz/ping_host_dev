#include "RequestStart.hpp"
using std::string;
RequestStart::RequestStart(Gtk::TextView *txt)
{
    tv = txt;
}

RequestStart::~RequestStart()
{
}

void RequestStart::exec_data(ItemHost* user_data, ClientRequest *http){
    RequestList list;
    auto buffer = tv->get_buffer();
    for (int i = 0; i < user_data->ping_rq_count; i++)
    {
        /* code */
         http->exec_request(user_data, &list, i+1);
        string result = list.get_item_all();
        buffer->set_text(result);
        tv->set_buffer(buffer);
    }
    
   
    //list.clear_all_item();
    //return result;

}