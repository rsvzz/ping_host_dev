#pragma once
#include <iostream>
#include <gtk/gtk.h>
#include <glib.h>
#include "model_struct.hpp"
using namespace std;

void content_body(GtkWidget *);
void content_head(GtkWidget *);
void btn_connect_clicked(GtkButton *btn, GtkTextView *data_user){
    //cout<<"clicked"<<endl;
    //gtk_widget_set_visible(GTK_WIDGET(btn), false);
    gtk_widget_set_sensitive(GTK_WIDGET(btn), false); //disable
    //gtk_text_view_set_editable(GTK_TEXT_VIEW(txtMessenger), false);
    //GtkTextView tview =  GTK_TEXT_VIEW(data_user);
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(data_user);
    gtk_text_buffer_set_text(buffer, "clicked add text TextView", -1);
    
}
void setup_ping_item(GtkListItemFactory *factory, GtkListItem *list_item) {
    GtkWidget *lb_name = gtk_label_new(nullptr);
    gtk_list_item_set_child(GTK_LIST_ITEM(list_item), lb_name);

}
void bind_ping_item(GtkListItemFactory *factory, GtkListItem *list_item) {
    GtkWidget *lb_name = gtk_list_item_get_child(list_item);
    PingItem *item = (PingItem*) gtk_list_item_get_item(list_item);
    // GtkWidget *lb_name = gtk_widget_get_first_child(GTK_WIDGET(box));
    gtk_label_set_text(GTK_LABEL (lb_name), item->value);
}


void activate(GApplication *app, gpointer *data) {
    GtkWidget *win = gtk_application_window_new(GTK_APPLICATION(app));
    gtk_window_set_title(GTK_WINDOW(win), "Ping Host Dev With GTK4/C++");
    gtk_window_set_resizable(GTK_WINDOW(win), false); // no maximize
    gtk_window_set_default_size(GTK_WINDOW(win), 500, 400);
    content_head(win);
    content_body(win); //create body content
    gtk_window_present(GTK_WINDOW(win));
    
}

void content_head(GtkWidget *app){
    GtkWidget *head = gtk_header_bar_new();
    GtkWidget *lblTitle = gtk_label_new("Dev Test Host");
    GtkWidget *btnSave = gtk_button_new_with_label("Save");
    //gtk_header_bar_set_show_title_buttons(GTK_HEADER_BAR(head), TRUE);//show title

    gtk_header_bar_set_title_widget(GTK_HEADER_BAR(head), lblTitle );
    GtkWidget *image = gtk_image_new_from_file("image/menu.png");
    gtk_button_set_child(GTK_BUTTON(btnSave), image);
    gtk_widget_set_size_request(btnSave, 50, 50);
    gtk_header_bar_pack_start(GTK_HEADER_BAR(head), btnSave);
    //gtk_header_bar_pack_start(GTK_HEADER_BAR(head), image);
   
    gtk_window_set_titlebar(GTK_WINDOW(app), head);

}

void content_body(GtkWidget *app){
    //add grid
    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_column_spacing(GTK_GRID(grid), 5); // border column
    gtk_grid_set_row_spacing(GTK_GRID(grid), 5); // border row
    //add child grid

    GtkWidget *lblHost = gtk_label_new("Host name :");
    GtkWidget *txtHost = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(txtHost), "http or https !!");
    GtkWidget *lblPing = gtk_label_new("Ping :");

    GtkTextBuffer* buffer = gtk_text_buffer_new(NULL);
  
    GtkWidget *txtMessenger = gtk_text_view_new_with_buffer(buffer);
    GtkWidget *sbMessenger = gtk_scrolled_window_new();
    
    gtk_text_buffer_set_text(buffer, "Hello, this is some text", -1);
    GtkWidget *boxMessenger = gtk_box_new(GtkOrientation::GTK_ORIENTATION_VERTICAL, 5);
    gtk_box_append(GTK_BOX(boxMessenger), txtMessenger);
    gtk_widget_set_size_request(sbMessenger,450, 300);
    gtk_widget_set_size_request(txtMessenger,450, 300);
    //gtk_widget_set_size_request(boxMessenger,450, 300);
    gtk_text_view_set_editable(GTK_TEXT_VIEW(txtMessenger), false);
    gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(sbMessenger), boxMessenger);
    gtk_widget_set_focusable(txtHost, true);
    //gtk_window_set_child(GTK_WINDOW(scMessenger), boxMessenger);
    
    //gtk_text_view_set_editable(GTK_TEXT_VIEW(txtMessenger), true);
    //gtk_entry_set_placeholder_text(GTK_ENTRY(txtMessenger), "Respose shows here!!");
    //gtk_widget_set_focusable(txtMessenger, false);
    //gtk_entry_set_overwrite_mode(GTK_ENTRY(txtMessenger), false);
    //gtk_widget_set_visible(txtMessenger, false);

    //list ping item

    GListStore *store = g_list_store_new(G_TYPE_OBJECT);
    g_list_store_append(store, ping_item_new(0,"10"));
    g_list_store_append(store, ping_item_new(1,"100"));
    g_list_store_append(store, ping_item_new(2,"1000"));
    g_list_store_append(store, ping_item_new(3,"10000"));

    GtkWidget *ddlPing = gtk_drop_down_new(nullptr, nullptr);
    GtkListItemFactory *factory = gtk_signal_list_item_factory_new ();
    g_signal_connect (factory, "setup", G_CALLBACK (setup_ping_item), NULL);
    g_signal_connect (factory, "bind", G_CALLBACK (bind_ping_item), NULL);
    gtk_drop_down_set_model (GTK_DROP_DOWN(ddlPing), G_LIST_MODEL(store));

    gtk_drop_down_set_factory(GTK_DROP_DOWN(ddlPing), factory);

    GtkWidget *btnConnect = gtk_button_new_with_label("Start");
    gtk_grid_attach(GTK_GRID(grid), lblHost, 0, 0, 1, 1); // w h cw rh
    gtk_grid_attach(GTK_GRID(grid), txtHost, 1, 0, 3, 1);
    gtk_grid_attach(GTK_GRID(grid), lblPing, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), ddlPing, 1, 1, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), btnConnect, 3, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), sbMessenger, 0, 2, 4, 1);

    gtk_grid_set_column_spacing(GTK_GRID(grid), 5);
    gtk_grid_set_row_spacing(GTK_GRID(grid), 5);
    gtk_widget_set_halign(grid, GtkAlign::GTK_ALIGN_CENTER);
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), true);

    //signal
    g_signal_connect (btnConnect, "clicked", G_CALLBACK (btn_connect_clicked), GTK_TEXT_VIEW(txtMessenger));

    gtk_window_set_child(GTK_WINDOW(app), grid); //app win main
}