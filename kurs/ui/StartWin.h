//
// Created by pbochkarev on 30.05.2023.
//

#ifndef C_PLUS_PLUS_STARTWIN_H
#define C_PLUS_PLUS_STARTWIN_H

#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include "LeftPanel.h"
#include "RightPanel.h"

class StartWin : public wxFrame{
public:
    StartWin();
    ~StartWin() override;
    void onExit();

    LeftPanel *leftPanel;
    RightPanel *rightPanel;
};


#endif //C_PLUS_PLUS_STARTWIN_H
