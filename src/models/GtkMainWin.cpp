#include <iostream>
#include "../headers/GtkMainWin.hpp"
using namespace std;

    Glib::RefPtr<ItemList> GtkMainWin::create_item(int value, const char *name) {
        return Glib::make_refptr_for_instance<ItemList>(new ItemList(value, name));
    }
//DropDown
    void GtkMainWin::on_clicked_start(){
        cout<<"Click"<<endl;
        txtHost->set_sensitive(false);
    }

    void GtkMainWin::on_clicked_option(){
        cout<<"Click"<<endl;
    }
    void GtkMainWin::on_setup(const Glib::RefPtr<Gtk::ListItem>& list_item) {
        // Crear un widget para cada elemento de la lista
        auto *label =new Gtk::Label();
        list_item->set_child(*label);
    }

    void GtkMainWin::on_bind(const Glib::RefPtr<Gtk::ListItem>& list_item) {
        // Vincular los datos del modelo al widget
        auto *label = (Gtk::Label*)list_item->get_child();
        if (label) {
            auto item = dynamic_pointer_cast<ItemList>(list_item->get_item());
            if(item != nullptr){
                label->set_label(item->get_name());
            }
            
        }
    }

    void GtkMainWin::on_open_menu(){

    }
    void GtkMainWin::on_save_menu(){

    }

GtkMainWin::GtkMainWin()
{
    //set_title("Hello");
    //set_title("Ping Host dev GTK4/C++ ");
    this->set_resizable(false);
    set_default_size(400,400);
    //btnButton("Clicked me!");
    btnButton =  new Gtk::Button("Clicked Me!!");
    mbOption =  new Gtk::MenuButton();
    //mbOption->set_always_show_arrow(true);
    //mbOption->set_label("File");
    /*
    Gtk::Label lbl_open("Open");
    Gtk::Label lbl_Save("Save");
    mbOption->set_child(lbl_open);
    mbOption->set_child(lbl_Save);
    */
    headerbar =  new Gtk::HeaderBar();
    txtRequest = new Gtk::TextView();
    fm_frame = new Gtk::Frame("Option Dev Host");
    auto box = new Gtk::Box(Gtk::Orientation::HORIZONTAL, 5);
    auto scroll = new Gtk::ScrolledWindow();
    scroll->set_child(*box);
    scroll->set_size_request(380, 220);
    txtRequest->set_size_request(400, 220);
    txtRequest->set_sensitive(false);
    box->append(*txtRequest);
    Gtk::Label lbltitle("Ping Host Gtkmm-4.0/C++");
    headerbar->set_title_widget(lbltitle);
    mbOption->set_icon_name("open-menu-symbolic");
    //headerbar->pack_start(*btnSave);
    //mbOption->set_always_show_arrow();
    /* sub menu
     auto sub_menu = Gio::Menu::create();
        sub_menu->append("Open File", "app.open");
        sub_menu->append("Save File", "app.save");
    */
    
    auto menu = Gio::Menu::create();
        menu->append("Open File", "app.open");
        menu->append("Save File", "app.save");
        //menu->append_submenu("Sub Mene", sub_menu); //Sub Menu
        //menu->append("Config", "app.config");

        // Set the menu model to the MenuButton
        
        auto app_menu = Gio::Application::get_default();
        app_menu->add_action("open", sigc::mem_fun(*this, &GtkMainWin::on_open_menu));
        app_menu->add_action("save", sigc::mem_fun(*this, &GtkMainWin::on_save_menu));
        
        //app_menu->add_action("config", sigc::mem_fun(*this, &GtkMainWin::on_save_menu));

        
        Gtk::PopoverMenu *popover_menu = new Gtk::PopoverMenu(menu);
        popover_menu->set_margin(10);
        //popover_menu.set_menu_model(menu);
        //popover_menu.set_has_arrow(false);
        
        mbOption->set_popover(*popover_menu);
        
        //mbOption->set_menu_model(menu);

        headerbar->pack_end(*mbOption);
    
    set_titlebar(*headerbar);
    //headerbar->set_show_title_buttons(true);
    //headerbar->set_show_close_button(true);
    
    
    grid = new Gtk::Grid();
    fm_frame->set_child(*grid);
    fm_frame->set_margin(10);
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
    btnStart->signal_clicked().connect(sigc::mem_fun(*this, &GtkMainWin::on_clicked_start));
    //mbOption->signal_show().connect(sigc::mem_fun(*this, &GtkMainWin::on_clicked_option));
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
    grid->attach(*scroll, 0, 2, 4, 1);

    //grid->set_column_homogeneous(true);
    grid->set_column_spacing(5);
    grid->set_column_homogeneous(true);
    grid->set_margin(5);
    grid->set_row_spacing(5);
    set_child(*fm_frame);
}

GtkMainWin::~GtkMainWin()
{
    /*
    delete title;
    delete btnButton;
    delete btnButton;
    delete headerbar;
    delete grid;
    delete lblHost;
    delete lblPing;
    delete txtHost;
    delete ddlPing;
    */
}
