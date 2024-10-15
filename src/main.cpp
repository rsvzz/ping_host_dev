#include "gtkwin/GtkMainWin.hpp"
#include <gtkmm-4.0/gtkmm/application.h>
#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
    auto app = Gtk::Application::create("org.gtkmm.examples.base");
    return app->make_window_and_run<GtkMainWin>(argc, argv);
}
