/***************************************************************
 * Name:      wxTestApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Brenton Poke (bpoke@umflint.edu)
 * Created:   2013-02-08
 * Copyright: Brenton Poke ()
 * License:
 **************************************************************/


#include <wx/wx.h>
#include "NPRModule.h"

class MyApp : public wxApp
{
    virtual bool OnInit();
};

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{

    wxInitAllImageHandlers();
    NPR_Module* frame = new NPR_Module(0L);

    frame->Show();


    return true;
}
