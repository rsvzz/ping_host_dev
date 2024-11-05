#pragma once
#include <gtk/gtk.h>
class HeaderBar
{
private:
    /* data */
    GtkWidget *head, *title;
public:
    HeaderBar(const char *);
    ~HeaderBar();
    /// @brief add widget headerbar start
    /// @param  
    void add_start(GtkWidget *);
     /// @brief add widget headerbar end
    /// @param  
    void add_end(GtkWidget *);
    GtkHeaderBar *getHeaderBar();
    GtkLabel *getTitle();
    /// @brief add headerbar to window
    /// @param  
    void add_window(GtkWindow *);
    
};
