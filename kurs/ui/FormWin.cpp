//
// Created by pbochkarev on 06.06.2023.
//

#include "FormWin.h"
#include <wx/sizer.h>




FormWin::FormWin(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos, const wxSize &size,
                 long style, const wxString &name, Staff employee) : wxDialog(parent, id, title, pos, size, style, name) {

   closeButton = new wxButton(this, wxID_CLOSE,
                              wxT("Close"),
                              wxPoint(100, 100),
                              wxSize(100, 10),
                              wxBU_BOTTOM);
    nameLabel = new wxStaticText(this, -1, wxString("Name: ", wxString(employee.getName())), wxPoint(10,10),
                                 wxDefaultSize, 0, "nameLabel");
    sernameLabel = new wxStaticText(this, -1, "Sername:", wxPoint(10,60),
                                    wxDefaultSize, 0, "sernameLabel");
    patronymicLabel = new wxStaticText(this, -1, "Patronymic:", wxPoint(10,110),
                                       wxDefaultSize, 0, "patronymic");
    workExperience = new wxStaticText(this, -1, "Work exp:", wxPoint(10,110),
                                       wxDefaultSize, 0, "work exp");
    employer = new wxStaticText(this, -1, "Employer:", wxPoint(10,110),
                                       wxDefaultSize, 0, "employer");
    averageGrade = new wxStaticText(this, -1, "Average Grade:", wxPoint(10,110),
                                wxDefaultSize, 0, "averageGrade");


    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

    // Добавление кнопок в управляющую сетку
    sizer->Add(nameLabel);
    sizer->Add(sernameLabel);
    sizer->Add(patronymicLabel);
    sizer->Add(workExperience);
    sizer->Add(employer);
    sizer->Add(averageGrade);



    sizer->Add(closeButton,0, wxALIGN_CENTER_HORIZONTAL, 10 );  // Параметры: элемент, пропорция, флаги, отступ


    // Установка управляющей сетки для диалогового окна
    SetSizer(sizer);
    Layout();
}

FormWin::~FormWin() {}