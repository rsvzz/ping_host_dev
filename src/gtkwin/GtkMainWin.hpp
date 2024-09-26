#pragma once

#include <gtkmm-4.0/gtkmm.h>
#include <giomm-2.68/giomm.h>
#include <glibmm-2.68/glibmm.h>



class ItemList : public Glib::Object{
    private:
        const char *name;
        int value;
    public:
        ItemList(int _value,const char *_name){
            value = _value;
            name = _name;
        };
        /// @brief property name
        /// @return Display name
        char *get_name() { return (char*)name; }
        /// @brief property value
        /// @return key
        int get_value() {return value;};
};

class GtkMainWin : public Gtk::Window
{
private:
    /* data */
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
    /// @brief Create obj ItemList
    /// @param value key
    /// @param name  Display name
    /// @return 
    Glib::RefPtr<ItemList> create_item(int value, const char *name);
    /// @brief Start connect host remote
    void on_clicked_start();

    void on_clicked_option();
    /// @brief Create object factory
    /// @param list_item 
    void on_setup(const Glib::RefPtr<Gtk::ListItem>& list_item);
    /// @brief Bind object factory
    /// @param list_item 
    void on_bind(const Glib::RefPtr<Gtk::ListItem>& list_item);
    /// @brief Option menu clicked Open
    void on_open_menu();
    /// @brief Option menu Clicked Save
    void on_save_menu();
public:
    GtkMainWin();
    ~GtkMainWin();
};

