#pragma once
#include "WinApp.hpp"

class Application : public WinApp{
private:
    /* data */
    const char *title;
public:
    Application(const char *, const char *, GApplicationFlags);
    ~Application();
    void Activate(GApplication*, gpointer*);
    
};
