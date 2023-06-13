//
// Created by pbochkarev on 06.06.2023.
//

#ifndef C_PLUS_PLUS_RIGHTPANEL_H
#define C_PLUS_PLUS_RIGHTPANEL_H

#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/wx.h>
#include <wx/listbox.h>
#include "FormWin.h"
#include "LeftPanel.h"
#include <wx/panel.h>


class RightPanel: public wxPanel {
public:
    RightPanel(wxPanel *parent);
    wxPanel *parentPanel;
    wxStaticText *textLabel;
    wxListBox *listOfStaff;
    wxArrayString staffArray; //вспомогательный массив для добавления элементов в ListBox
    void addStaff(wxString staff);
    void clickOnStaff(wxCommandEvent& event);

};


#endif //C_PLUS_PLUS_RIGHTPANEL_H
