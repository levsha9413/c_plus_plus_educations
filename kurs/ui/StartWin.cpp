//
// Created by pbochkarev on 30.05.2023.
//

#include "StartWin.h"

StartWin::StartWin():wxFrame(NULL, wxID_ANY, "Start window") {

    wxPanel* panel = new wxPanel(this, wxID_ANY, wxPoint(10,50), wxSize(1000,1000));


    //Старый вариант:
    //Connect(wxID_EXIT, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(StartWin::onExit));

    wxBoxSizer* hBox = new wxBoxSizer(wxHORIZONTAL);
    leftPanel = new LeftPanel(panel);
    rightPanel = new RightPanel(panel);

    hBox->Add(leftPanel, 1, wxEXPAND | wxALL, 5);
    hBox->Add(rightPanel, 1, wxEXPAND | wxALL, 5);
    panel -> SetSizer(hBox);

}

StartWin::~StartWin() {

}

void StartWin::onExit() {
    wxPuts("exit");
    Close(true);
}
