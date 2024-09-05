#pragma once
#include <gtk/gtk.h>

class WinApp
{
private:
    /* data */
    GtkApplication *app;
protected:
    GtkWindow *window;
public:
    WinApp(const char *, GApplicationFlags);
    ~WinApp();
    /// @brief Param main args
    /// @param  
    /// @param  
    /// @return status App
    int Run(int, char**);
    GtkWindow *getWindow();
    GtkApplication *getApplication();
    /// @brief dafult width y height
    /// @param  
    /// @param  
    void setDefaultWinSize(int, int);
    /// @brief Set title window
    /// @param  
    void setTitle(const char *);
    /// @brief desable width y height window
    /// @param  
    void setWinResizable(bool);
};


