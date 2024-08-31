#include "headers/AppWin.hpp"
//#include "headers/CurlClient.hpp"
//#include "headers/HostClient.hpp"

int main(int argc, char **argv) {
    GtkApplication *app;
    int stat;
    app = gtk_application_new("com.gtk4.pinghosttestdev", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    stat = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return stat;
}