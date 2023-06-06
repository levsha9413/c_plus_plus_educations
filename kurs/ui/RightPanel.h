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


class RightPanel: public wxPanel {
public:
    RightPanel(wxPanel *parent);
    wxStaticText *textLabel;
    wxListBox *listOfStaff;
    wxArrayString staffArray; //вспомогательный массив для добавления элементов в ListBox
    void addStaff(wxString staff);

};


#endif //C_PLUS_PLUS_RIGHTPANEL_H
