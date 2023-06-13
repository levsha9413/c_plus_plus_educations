//
// Created by pbochkarev on 06.06.2023.
//

#ifndef C_PLUS_PLUS_FORMWIN_H
#define C_PLUS_PLUS_FORMWIN_H
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/window.h>
#include <wx/textctrl.h>
#include <wx/stattext.h>
#include "../Staff.h"




class FormWin: public wxDialog{
public:
    FormWin(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos, const wxSize &size, long style,
            const wxString &name, Staff employee);

    ~FormWin() override;
    wxButton *closeButton;
    wxStaticText  *nameLabel;
    wxStaticText *sernameLabel;
    wxStaticText *patronymicLabel;
    wxStaticText *workExperience;
    wxStaticText *employer;
    wxStaticText *averageGrade;
};


#endif //C_PLUS_PLUS_FORMWIN_H
