
//#include <gtk/gtk.h>
#include "headers/Application.hpp"
void win_activate(GApplication *app, gpointer *data);
void Application::Activate(GApplication *app, gpointer *data){
    GtkWidget *_win = gtk_application_window_new(GTK_APPLICATION(app));
    gtk_window_present(GTK_WINDOW(_win));

            /*
    GtkWidget *_win = gtk_application_window_new(GTK_APPLICATION(app));
    window =  GTK_WINDOW(_win);
    gtk_window_present(window);*/
}

Application::Application(const char *_title, const char *appId, GApplicationFlags aFlag) : WinApp(appId, aFlag)
{
    title = _title;
    GtkApplication *app = gtk_application_new(appId, aFlag);
    g_signal_connect(app, "activate", G_CALLBACK(Application::Activate), NULL);
}

Application::~Application()
{
    delete title;
}




void win_activate(GApplication *app, gpointer *data){
    GtkWidget *_win = gtk_application_window_new(GTK_APPLICATION(app));
    gtk_window_set_title(GTK_WINDOW(_win), "Hi !!");
    gtk_window_present(GTK_WINDOW(_win));

}