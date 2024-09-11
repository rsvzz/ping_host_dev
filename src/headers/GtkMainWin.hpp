#pragma once
#include <gtkmm-4.0/gtkmm/window.h>
#include <gtkmm-4.0/gtkmm/button.h>
#include <gtkmm-4.0/gtkmm/headerbar.h>
#include <gtkmm-4.0/gtkmm/menubutton.h>
#include <gtkmm-4.0/gtkmm/label.h>
#include <gtkmm-4.0/gtkmm/grid.h>
#include <gtkmm-4.0/gtkmm/entry.h>
#include <gtkmm-4.0/gtkmm/dropdown.h>
#include <gtkmm-4.0/gtkmm/listitem.h>
#include <gtkmm-4.0/gtkmm/signallistitemfactory.h>
#include <gtkmm-4.0/gtkmm/frame.h>
#include <gtkmm-4.0/gtkmm/textview.h>
#include <gtkmm-4.0/gtkmm/box.h>
#include <gtkmm-4.0/gtkmm/popovermenu.h>
#include <gtkmm-4.0/gtkmm/spinbutton.h>
#include <gtkmm-4.0/gtkmm/scrolledwindow.h>
#include <giomm-2.68/giomm/liststore.h>
#include <giomm-2.68/giomm/menu.h>
#include <giomm-2.68/giomm.h>
#include <giomm-2.68/giomm/application.h>
#include <glibmm-2.68/glibmm/object.h>


class ItemList : public Glib::Object{
    private:
        const char *name;
        int value;
    public:
        ItemList(int _value,const char *_name){
            value = _value;
            name = _name;
        };

        char *get_name() { return (char*)name; }
        int get_value() {return value;};

};

class GtkMainWin : public Gtk::Window
{
private:
    /* data */
    Gtk::Button *btnButton;
    Gtk::MenuButton *mbOption;
    Gtk::HeaderBar *headerbar;
    Gtk::Grid *grid;
    Gtk::Entry *txtHost;
    Gtk::Label *lblHost;
    Gtk::DropDown *ddlPing;
    Gtk::Label *lblPing;
    Gtk::Button *btnStart;
    Gtk::Frame *fm_frame;
    Gtk::TextView *txtRequest;

     Glib::RefPtr<ItemList> create_item(int value, const char *name);
    //DropDown
    void on_clicked_start();

    void on_clicked_option();
    void on_setup(const Glib::RefPtr<Gtk::ListItem>& list_item);

    void on_bind(const Glib::RefPtr<Gtk::ListItem>& list_item);
    void on_open_menu();

    void on_save_menu();
public:
    GtkMainWin();
    ~GtkMainWin();
    
};

