#include <iostream>
#include <cstdio>
#include "GtkMainWin.hpp"
#include <thread>
using namespace std;

Glib::RefPtr<ItemList> GtkMainWin::create_item(int value, const char *name)
{
    return Glib::make_refptr_for_instance<ItemList>(new ItemList(value, name));
}
void GtkMainWin::OnBtnStart(ClientRequest *client)
{
    auto item = dynamic_pointer_cast<ItemList>(ddlPing->get_selected_item());
    // Exec ping server
    
    ItemHost udata;

    char *host_name = new char[txtHost->get_buffer()->get_text().length() + 1];
    strcpy(host_name, txtHost->get_buffer()->get_text().c_str());
    // printf("%s \n", host_name);

    udata.host_name = host_name;
    udata.ping_rq_count = item->get_value();
    //printf("H: %s P: %d \n", udata.host_name, udata.ping_rq_count);
    RequestStart exe(txtRequest);
    exe.exec_data(&udata, client);
    //buffer->set_text(data);
    //txtRequest->set_buffer(buffer);
    txtRequest->set_sensitive(true);
    txtHost->set_sensitive(true);
    ddlPing->set_sensitive(true);
    btnStart->set_sensitive(true);
    btnStart->set_icon_name("mail-send-receive-symbolic");
}

void GtkMainWin::on_clicked_start(ClientRequest *client)
{

    bool status = false;
   // if (strcmp(btnStart->get_icon_name().c_str(), "mail-send-receive-symbolic") == 0)
    // {
        txtHost->set_sensitive(status);
        ddlPing->set_sensitive(status);
        txtRequest->set_sensitive(status);
        btnStart->set_sensitive(status);
        btnStart->set_icon_name("system-reboot-symbolic");
        // auto cl = std::make_shared<ClientRequest*>(client);
        thread tr(&GtkMainWin::OnBtnStart, this, client);
        tr.detach();
    /*}
    else
    {
        status = true;
        txtHost->set_sensitive(status);
        ddlPing->set_sensitive(status);
        txtRequest->set_sensitive(false);
        btnStart->set_icon_name("mail-send-receive-symbolic");
    }
    */
};

void GtkMainWin::on_clicked_option()
{
    cout << "Click" << endl;
}
void GtkMainWin::on_setup(const Glib::RefPtr<Gtk::ListItem> &list_item)
{
    // Crear un widget para cada elemento de la lista
    auto *label = new Gtk::Label();
    list_item->set_child(*label);
}

void GtkMainWin::on_bind(const Glib::RefPtr<Gtk::ListItem> &list_item)
{
    // Vincular los datos del modelo al widget
    auto *label = (Gtk::Label *)list_item->get_child();
    if (label)
    {
        auto item = dynamic_pointer_cast<ItemList>(list_item->get_item());
        if (item != nullptr)
        {
            label->set_label(item->get_name());
        }
    }
}

void GtkMainWin::on_open_menu()
{
    auto file = Gtk::FileDialog::create();
    file->set_title("Open File Request");

    file->open([this](const Glib::RefPtr<Gio::AsyncResult>& result){
         auto file_dialog = dynamic_pointer_cast<Gtk::FileDialog>(result->get_source_object_base());
         if(file_dialog != nullptr){
             cout<<file_dialog->open_finish(result)->get_path()<<endl;
         }
    });


    
}

void GtkMainWin::on_save_menu()
{
    if(txtHost->get_text_length() > 0){
        char *host_name = new char[txtHost->get_buffer()->get_text().length() + 1];
        strcpy(host_name, txtHost->get_buffer()->get_text().c_str());
        auto item = dynamic_pointer_cast<ItemList>(ddlPing->get_selected_item());
        int req = item->get_value();
        cout<<host_name<<" "<<req<<endl;

        auto file = Gtk::FileDialog::create();
    file->set_title("Save File Request");
        auto filters = Gio::ListStore<Glib::Object>::create();
        auto filtro = Gtk::FileFilter::create();
        filtro->add_mime_type("application/json");
        filtro->set_name("Json File");
        filters->append(filtro);
       file->set_filters(filters);
    file->save([this](const Glib::RefPtr<Gio::AsyncResult>& result){
        
         try{
             auto file_dialog = dynamic_pointer_cast<Gtk::FileDialog>(result->get_source_object_base());
              auto res = file_dialog->save_finish(result);
              cout<<res->get_path()<<endl;
         }
         catch(Gio::Error ex){

         }
             
    });
    
    }   
    else{
        auto dialog = Gtk::AlertDialog::create();
        dialog->set_detail("Requiere que rellene los datos.");
        dialog->set_message("Informacion Requerida");
        dialog->choose([this](const Glib::RefPtr<Gio::AsyncResult>& result){
            auto dialog = dynamic_pointer_cast<Gtk::AlertDialog>(result->get_source_object_base());
            dialog->choose_finish(result);

        });
    }
}

GtkMainWin::GtkMainWin()
{
    // set_title("Hello");
    // set_title("Ping Host dev GTK4/C++ ");
    set_default_size(400, 400);
    set_resizable(false);
    // manejador request test

    http = new ClientRequest;
    /*
    RequestItem item1 = {1, 200, "Correcto"};
    RequestItem item2 = {2, 200, "Correcto"};
    RequestItem item3 = {3, 200, "Correcto"};
    list->add(&item1);
    list->add(&item2);
    list->add(&item3);
    */
    // btnButton("Clicked me!");
    mbOption = new Gtk::MenuButton();
    btnStart = new Gtk::Button("Start");
    btnStart->set_icon_name("mail-send-receive-symbolic");
    // mbOption->set_always_show_arrow(true);
    // mbOption->set_label("File");
    /*
    Gtk::Label lbl_open("Open");
    Gtk::Label lbl_Save("Save");
    mbOption->set_child(lbl_open);
    mbOption->set_child(lbl_Save);
    */
    headerbar = new Gtk::HeaderBar();
    // headerbar->set_size_request(-1, 30);
    txtRequest = new Gtk::TextView();
    fm_frame = new Gtk::Frame("Option Dev Host");
    fm_frame->set_margin(10);
    grid = new Gtk::Grid();
    grid->set_size_request(350, 350);
    grid->set_halign(Gtk::Align::CENTER);

    auto box = new Gtk::Box(Gtk::Orientation::HORIZONTAL, 5);
    auto scroll = new Gtk::ScrolledWindow();
    scroll->set_child(*box);
    scroll->set_size_request(300, 220);
    txtRequest->set_size_request(280, 200);
    txtRequest->set_sensitive(false);
    box->append(*txtRequest);
    Gtk::Label lbltitle("Ping Host Gtkmm-4.0/C++");
    headerbar->set_title_widget(lbltitle);
    mbOption->set_icon_name("open-menu-symbolic");
    // headerbar->pack_start(*btnSave);
    // mbOption->set_always_show_arrow();
    /* sub menu
     auto sub_menu = Gio::Menu::create();
        sub_menu->append("Open File", "app.open");
        sub_menu->append("Save File", "app.save");
    */

    auto menu = Gio::Menu::create();
    menu->append("Open File", "app.open");
    menu->append("Save File", "app.save");
    // menu->append_submenu("Sub Mene", sub_menu); //Sub Menu
    // menu->append("Config", "app.config");

    // Set the menu model to the MenuButton

    auto app_menu = Gio::Application::get_default();
    app_menu->add_action("open", sigc::mem_fun(*this, &GtkMainWin::on_open_menu));
    app_menu->add_action("save", sigc::mem_fun(*this, &GtkMainWin::on_save_menu));

    // app_menu->add_action("config", sigc::mem_fun(*this, &GtkMainWin::on_save_menu));

    /*
    Gtk::PopoverMenu *popover_menu = new Gtk::PopoverMenu(menu);
    popover_menu->set_margin(10);
    //popover_menu.set_menu_model(menu);
    popover_menu->set_has_arrow(true);

    mbOption->set_popover(*popover_menu);*/

    mbOption->set_menu_model(menu);

    headerbar->pack_end(*mbOption);

    set_titlebar(*headerbar);
    // headerbar->set_show_title_buttons(true);
    // headerbar->set_show_close_button(true);

    lblHost = new Gtk::Label("HostName:");

    txtHost = new Gtk::Entry();
    // txtHost->set_text("https://example.com"); //test url
    lblPing = new Gtk::Label("Ping Host:");
    const auto model = Gio::ListStore<ItemList>::create();
    model->append(create_item(10, "Request 10"));
    model->append(create_item(20, "Request 20"));
    model->append(create_item(30, "Request 30"));

    auto factory = Gtk::SignalListItemFactory::create();
    factory->signal_setup().connect(sigc::mem_fun(*this, &GtkMainWin::on_setup));
    factory->signal_bind().connect(sigc::mem_fun(*this, &GtkMainWin::on_bind));
    ddlPing = new Gtk::DropDown();
    ddlPing->set_model(model);
    ddlPing->set_factory(factory);

    btnStart->signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &GtkMainWin::on_clicked_start), http));
    // mbOption->signal_show().connect(sigc::mem_fun(*this, &GtkMainWin::on_clicked_option));
    // lblHost->set_size_request(100, 30);
    lblHost->set_halign(Gtk::Align::END);
    // lblPing->set_size_request(100, 30);
    lblPing->set_halign(Gtk::Align::END);

    txtHost->set_placeholder_text("Url host");
    grid->attach(*lblHost, 0, 0, 1, 1);
    grid->attach(*txtHost, 1, 0, 3, 1);
    grid->attach(*lblPing, 0, 1, 1, 1);
    grid->attach(*ddlPing, 1, 1, 2, 1);
    grid->attach(*btnStart, 3, 1, 1, 1);
    grid->attach(*scroll, 0, 2, 4, 1);

    // grid->set_column_homogeneous(true);
    grid->set_column_spacing(5);
    // grid->set_column_homogeneous(true);
    grid->set_margin(5);
    grid->set_row_spacing(5);

    fm_frame->set_child(*grid);
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
