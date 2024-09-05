#pragma once
#include <gtkmm-4.0/gtkmm/window.h>
#include <gtkmm-4.0/gtkmm/button.h>
#include <gtkmm-4.0/gtkmm/headerbar.h>
#include <gtkmm-4.0/gtkmm/label.h>
#include <gtkmm-4.0/gtkmm/grid.h>
#include <gtkmm-4.0/gtkmm/entry.h>
#include <gtkmm-4.0/gtkmm/dropdown.h>

class GtkMainWin : public Gtk::Window
{
private:
    /* data */
    const char *title;
    Gtk::Button *btnButton;
    Gtk::Button *btnOpen;
    Gtk::Button *btnSave;
    Gtk::HeaderBar *headerbar;
    Gtk::Grid *grid;
    Gtk::Entry *txtHost;
    Gtk::Label *lblHost;
    Gtk::DropDown *ddlPing;
    Gtk::Label *lblPing;
    Gtk::Button *btnStart;
public:
    GtkMainWin();
    ~GtkMainWin();
    
};

GtkMainWin::GtkMainWin()
{
    //set_title("Hello");
    //set_title("Ping Host dev GTK4/C++ ");
    this->set_resizable(false);
    set_default_size(300,300);
    //btnButton("Clicked me!");
    btnButton =  new Gtk::Button("Clicked Me!!");
    btnOpen =  new Gtk::Button("Open");
    btnSave =  new Gtk::Button("Save");
    headerbar =  new Gtk::HeaderBar();
    
    Gtk::Label lbltitle("Application Headerbar Label");
    headerbar->set_title_widget(lbltitle);
    btnOpen->set_icon_name("document-open-symbolic");
    btnSave->set_icon_name("document-save-symbolic");
    headerbar->pack_start(*btnSave);
    headerbar->pack_end(*btnOpen);
    this->set_titlebar(*headerbar);
    
    grid = new Gtk::Grid();
    grid->set_margin_top(10);
    lblHost = new Gtk::Label("HostName:");
   
    txtHost = new Gtk::Entry();
    lblPing = new Gtk::Label("Ping Host:");
    ddlPing = new Gtk::DropDown();
    btnStart = new Gtk::Button("Start");
    lblHost->set_size_request(100, 30);
    lblHost->set_halign(Gtk::Align::START);
    lblPing->set_size_request(100, 30);
    lblPing->set_halign(Gtk::Align::START);

    txtHost->set_placeholder_text("Url host");
    grid->attach(*lblHost, 0, 0, 1, 1);
    grid->attach(*txtHost, 1, 0, 3, 1);
    grid->attach(*lblPing, 0, 1, 1, 1);
    grid->attach(*ddlPing, 1, 1, 2, 1);
    grid->attach(*btnStart, 3, 1, 1, 1);
    //grid->set_column_homogeneous(true);
    grid->set_column_spacing(5);
    //grid->set_row_homogeneous(true);
    grid->set_row_spacing(5);
    set_child(*grid);
    
}

GtkMainWin::~GtkMainWin()
{
    delete title;
    delete btnButton;
    delete btnOpen;
    delete btnSave;
    delete headerbar;
    delete grid;
    delete lblHost;
    delete lblPing;
    delete txtHost;
    delete ddlPing;
    
}
