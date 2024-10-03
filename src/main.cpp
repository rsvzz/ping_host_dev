//#include "headers/AppWin.hpp"
//#include "headers/Application.hpp"
//#include "headers/CurlClient.hpp"
//#include "headers/HostClient.hpp"
#include "gtkwin/GtkMainWin.hpp"
#include <gtkmm-4.0/gtkmm.h>
#include <iostream>
using namespace std;
/*#include <gtkmm-4.0/gtkmm/window.h>


class AppGtk : public Gtk::Window{
    private:
    public:
        AppGtk(){
        
        };
        ~AppGtk();
};

void Activate(GApplication *app, gpointer *data){

    GtkWidget *_win = gtk_application_window_new(GTK_APPLICATION(app));
    GtkWindow *window =  GTK_WINDOW(_win);
    gtk_window_present(window);
}

*/


int main(int argc, char* argv[])
{
    auto app = Gtk::Application::create("org.gtkmm.examples.base");
    return app->make_window_and_run<GtkMainWin>(argc, argv);
}
/*
int main(int argc, char *args[]) {
   
    //Application app("Ping Host GTK4/C++","com.gtk4.devhostping", G_APPLICATION_DEFAULT_FLAGS);
    //g_signal_connect(app.getApplication(), "activate", G_CALLBACK(Activate), NULL);
    //app.setDefaultWinSize(300,300);
    //app.setWinResizable(false);
    //app.show_window();
    //int state = g_application_run(G_APPLICATION(app.getApplication()), argc, args);
    auto app = Gtk::Application::create("com.myapp.gtkmm4.hostpingtest");
   return app->make_window_and_run<GtkMainWin>(argc, args);
}
*/

 /*
    GtkApplication *app;
    int stat;
    app = gtk_application_new("com.gtk4.pinghosttestdev", G_APPLICATION_DEFAULT_FLAGS);

    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    stat = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    */