#pragma once
#include <iostream>
#include <gtkmm-4.0/gtkmm/window.h>
#include <gtkmm-4.0/gtkmm/button.h>
#include <gtkmm-4.0/gtkmm/headerbar.h>
#include <gtkmm-4.0/gtkmm/label.h>
#include <gtkmm-4.0/gtkmm/grid.h>
#include <gtkmm-4.0/gtkmm/entry.h>
#include <gtkmm-4.0/gtkmm/dropdown.h>
#include <gtkmm-4.0/gtkmm/listitem.h>
#include <gtkmm-4.0/gtkmm/signallistitemfactory.h>
#include <giomm-2.68/giomm/liststore.h>
#include <glibmm-2.68/glibmm/object.h>
using namespace std;
class ModelColumns : public Glib::Object
{
public:
  int m_col_id;
  Glib::ustring m_col_name;

  static Glib::RefPtr<ModelColumns> create(
    int col_id, const Glib::ustring& col_name)
  {
    return Glib::make_refptr_for_instance<ModelColumns>(
      new ModelColumns(col_id, col_name));
  }

protected:
  ModelColumns(int col_id, const Glib::ustring& col_name)
  : m_col_id(col_id), m_col_name(col_name)
  {}
};


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

Glib::RefPtr<ItemList> create_item(int value, const char *name) {
    return Glib::make_refptr_for_instance<ItemList>(new ItemList(value, name));
}


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

    //DropDown

    void on_setup(const Glib::RefPtr<Gtk::ListItem>& list_item) {
        // Crear un widget para cada elemento de la lista
        auto *label =new Gtk::Label();
        list_item->set_child(*label);
    }

    void on_bind(const Glib::RefPtr<Gtk::ListItem>& list_item) {
        // Vincular los datos del modelo al widget
        auto *label = (Gtk::Label*)list_item->get_child();
        if (label) {
            auto item = dynamic_pointer_cast<ItemList>(list_item->get_item());
            if(item != nullptr){
                label->set_label(item->get_name());
            }
            
        }
    }
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
    lblHost = new Gtk::Label("HostName:");
   
    txtHost = new Gtk::Entry();
    lblPing = new Gtk::Label("Ping Host:");
    const auto model =  Gio::ListStore<ItemList>::create();

    model->append(create_item(1, "Elemento 1"));
    model->append(create_item(2, "Elemento 2"));
    model->append(create_item(3, "Elemento 3"));
    
    
    auto factory = Gtk::SignalListItemFactory::create();
    factory->signal_setup().connect(sigc::mem_fun(*this, &GtkMainWin::on_setup));
    factory->signal_bind().connect(sigc::mem_fun(*this, &GtkMainWin::on_bind));
    ddlPing = new Gtk::DropDown();
    ddlPing->set_model(model);
    ddlPing->set_factory(factory);
    
    btnStart = new Gtk::Button("Start");
    btnStart->set_icon_name("mail-send-receive-symbolic");
    lblHost->set_size_request(100, 30);
    lblHost->set_halign(Gtk::Align::END);
    lblPing->set_size_request(100, 30);
    lblPing->set_halign(Gtk::Align::END);

    txtHost->set_placeholder_text("Url host");
    grid->attach(*lblHost, 0, 0, 1, 1);
    grid->attach(*txtHost, 1, 0, 3, 1);
    grid->attach(*lblPing, 0, 1, 1, 1);
    grid->attach(*ddlPing, 1, 1, 2, 1);
    grid->attach(*btnStart, 3, 1, 1, 1);

    //grid->set_column_homogeneous(true);
    grid->set_column_spacing(5);
    grid->set_column_homogeneous(true);
    grid->set_margin(5);
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
