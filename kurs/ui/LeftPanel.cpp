//
// Created by pbochkarev on 06.06.2023.
//

#include "LeftPanel.h"
#include "StartWin.h"

const int ID_PLUS=101;
const int ID_MINUS=102;

LeftPanel::LeftPanel(wxPanel *parent)
: wxPanel(parent, -1, wxPoint(-1,-1), wxSize(280,1000), wxBORDER_SUNKEN) {

    count = 0;
    parentPanel = parent;
    wxArrayString staffCategoryes;
    staffCategoryes.Add("Developer");
    staffCategoryes.Add("Tester");
    wxArrayString employeList;
    employeList.Add("OneSoft");
    employeList.Add("Tenzor");
    employeList.Add("GraphiSoftware");


    nameLabel = new wxStaticText(this, -1, "Name:", wxPoint(10,10),
                                 wxDefaultSize, 0, "nameLabel");
    nameInput = new wxTextCtrl(this, -1, "", wxPoint(100,10),
                              wxSize(150,25), 0, wxDefaultValidator, "name");

    sernameLabel = new wxStaticText(this, -1, "Sername:", wxPoint(10,60),
                                    wxDefaultSize, 0, "sernameLabel");
    sernameInput = new wxTextCtrl(this, -1, "", wxPoint(100,60),
                                  wxSize(150,25), 0, wxDefaultValidator, "Sername");

    patronymicLabel = new wxStaticText(this, -1, "Patronymic:", wxPoint(10,110),
                                     wxDefaultSize, 0, "patronymic");
    patronymicInput = new wxTextCtrl(this, -1, "", wxPoint(100,110),
                                     wxSize(150,25), 0, wxDefaultValidator, "patronymic");

    employerListLabel = new wxStaticText(this, -1, "Employer:", wxPoint(10,160),
                                         wxDefaultSize, 0, "employer list label");
    employerList = new wxChoice(this, wxID_ANY, wxPoint(100, 160), wxSize(150,25),
                                employeList,
                                0, wxDefaultValidator,
                                wxT("Employer"));

    choiceStaffCategoryLabel = new wxStaticText(this, -1, "Specialization:", wxPoint(10,210),
                                            wxDefaultSize, 0, "Specialization");
    choiceStaffCategory = new wxChoice(this, wxID_ANY, wxPoint(100, 210),
                                       wxSize(150,25),
                                       staffCategoryes,
                                       0, wxDefaultValidator,
                                       wxT("Специализация"));

    datepickerLabel = new wxStaticText(this, -1, "Date of \nstart work:", wxPoint(10,250),
                                       wxDefaultSize, 0, "data picker label");
    datepicker = new wxDatePickerCtrl();

    btnPlus = new wxButton(this, ID_PLUS, wxT("+"), wxPoint(10,310));
    btnMinus = new wxButton(this, ID_MINUS, wxT("-"), wxPoint(100,310));
    exitButton = new wxButton(this, wxID_EXIT, wxT("Выход"), wxPoint(10, 360));


    btnPlus->Bind(wxEVT_BUTTON, &LeftPanel::OnPlus, this);
    btnMinus->Bind(wxEVT_BUTTON, &LeftPanel::OnMinus, this);
    exitButton->Bind(wxEVT_BUTTON, &LeftPanel::onExit, this);

}

void LeftPanel::OnPlus(wxCommandEvent &event) {
    count++;

    StartWin *startWin = (StartWin *) parentPanel -> GetParent();
    startWin -> rightPanel -> textLabel -> SetLabel(wxString::Format(wxT("%d"), count));
    switch (choiceStaffCategory->GetSelection()){
        case 0:
            staffList.push_back(Developer("Михаил",
                                          string(sernameInput->GetLineText(0)),
                                         "Дмитриевич",
                                         "ООО Лев",
                                         wxDateTime::wxDateTime_t(12),
                                         wxDateTime::Month(wxDateTime::Jan),
                                         2023,
                                         2, 4, 2));
            startWin->rightPanel->addStaff(staffList[staffList.size()-1].getSurname());
            sernameInput->SetValue("");
            break;
        case 1:
            staffList.push_back(Tester("Иван",
                                            "Иванов",
                                            "Иванович",
                                            "ООО Зебра",
                                            wxDateTime::wxDateTime_t(12),
                                            wxDateTime::Month(wxDateTime::Jan),
                                            2022,
                                            7, 3, 1));
            startWin->rightPanel->addStaff(staffList[staffList.size()-1].getSurname());
            break;

    }
    wxPrintf( "Выбран пункт %d\n", choiceStaffCategory->GetSelection());
}

void LeftPanel::OnMinus(wxCommandEvent &event) {
    count--;
    StartWin *startWin = (StartWin *) parentPanel->GetParent();
    startWin -> rightPanel -> textLabel ->SetLabel((wxString::Format(wxT("%d"), count)));

}

void LeftPanel::onExit(wxCommandEvent &event) {
    StartWin *startWin = (StartWin *) parentPanel->GetParent();
    startWin -> onExit();
}

