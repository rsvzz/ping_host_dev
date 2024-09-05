#include <gtk/gtk.h>
#include <headers/HeaderBar.hpp>

HeaderBar::HeaderBar(const char *title)
{
    head = gtk_header_bar_new();
    *title = gtk_label_new(title_bar);
    gtk_header_bar_set_title_widget(GTK_HEADER_BAR(head), title);
}

HeaderBar::~HeaderBar()
{
    delete title;
    delete head;
}

void HeaderBar::add_start(GtkWidget *obj){
    gtk_header_bar_pack_start(GTK_HEADER_BAR(head), obj);
}

void HeaderBar::add_end(GtkWidget *obj){
    gtk_header_bar_pack_end(GTK_HEADER_BAR(head), obj);
}

GtkLabel *HeaderBar::getTitle() return GTK_LABEL(title);
GtkHeaderBar *HeaderBar::getTitle() return GTK_HEADER_BAR(head);

void HeaderBar::add_window(GtkWindow *win){
    gtk_window_set_titlebar(win, head);
}