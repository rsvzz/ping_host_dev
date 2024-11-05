#pragma once
#include <gtkmm-4.0/gtkmm/textview.h>
#include "../../curl/ClientRequest.hpp"
#include <string>

using namespace std;
using std::string;
class RequestStart
{
private:
    /* data */
    Gtk::TextView *tv;
public:
    RequestStart(Gtk::TextView *);
    ~RequestStart();
    void exec_data(ItemHost*, ClientRequest*);
};


