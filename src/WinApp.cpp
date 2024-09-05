#include "headers/WinApp.hpp"
WinApp::WinApp(const char *appId, GApplicationFlags flag)
{
    app = gtk_application_new(appId, flag);
}

WinApp::~WinApp()
{
    delete app;
    delete window;
    g_object_unref(app);
}

void WinApp::setDefaultWinSize(int w, int h){
    gtk_window_set_default_size(window, w, h);
}
void WinApp::setTitle(const char *_titleWin){
    gtk_window_set_title(window, _titleWin);
}
void WinApp::setWinResizable(bool status){
    gtk_window_set_resizable(window, status);
}

int WinApp::Run(int argc, char **agrv){
    return g_application_run(G_APPLICATION(app), argc, agrv);
}
GtkWindow *WinApp::getWindow() {return window;}
GtkApplication *WinApp::getApplication() {return app;}

