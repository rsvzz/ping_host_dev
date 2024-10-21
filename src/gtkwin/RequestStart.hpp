#pragma once
#include <iostream>
#include "../http/ClientRequest.hpp"
#include <gtkmm-4.0/gtkmm/textview.h>
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


