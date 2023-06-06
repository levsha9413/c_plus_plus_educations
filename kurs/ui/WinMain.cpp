//
// Created by pbochkarev on 23.05.2023.
//

// wxWidgets "Hello World" Program

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#include "StartWin.h"
#endif

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    StartWin *frame = new StartWin();
    frame->Show(true);
    return true;
}
