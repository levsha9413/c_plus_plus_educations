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

    staffCategoryes.Add("Developer");
    staffCategoryes.Add("Tester");

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
    datepicker = new wxDatePickerCtrl(this, wxID_ANY, wxDefaultDateTime, wxPoint(100, 250),
                                      wxDefaultSize, wxDP_DEFAULT | wxDP_SHOWCENTURY, wxDefaultValidator );

    systemSkillsLabel = new wxStaticText(this, -1, "System Skill:", wxPoint(10,310),
                                 wxDefaultSize, 0, "systemSkillsLabel");
    systemSkillsInput = new wxTextCtrl(this, -1, "", wxPoint(100,310),
                               wxSize(150,25), 0, wxDefaultValidator, "systemSkillsInput");

    languageSkillsLabel = new wxStaticText(this, -1, "Language Skill:", wxPoint(10,360),
                                         wxDefaultSize, 0, "languageSkillsLabel");
    languageSkillsInput = new wxTextCtrl(this, -1, "", wxPoint(100,360),
                                       wxSize(150,25), 0, wxDefaultValidator, "languageSkillsInput");

    dataBaseSkillsLabel = new wxStaticText(this, -1, "DB Skill:", wxPoint(10,410),
                                           wxDefaultSize, 0, "dataBaseSkillsLabel");
    dataBaseSkillsInput = new wxTextCtrl(this, -1, "", wxPoint(100,410),
                                         wxSize(150,25), 0, wxDefaultValidator, "dataBaseSkillsInput");

    communicationSkillsLabel = new wxStaticText(this, -1, "Communication Skill:", wxPoint(10,310),
                                           wxDefaultSize, 0, "communicationSkillsLabel");
    communicationSkillsInput = new wxTextCtrl(this, -1, "", wxPoint(100,310),
                                         wxSize(150,25), 0, wxDefaultValidator, "communicationSkillsInput");

    testSkillsLabel = new wxStaticText(this, -1, "Test Skill:", wxPoint(10,360),
                                                wxDefaultSize, 0, "testSkillsLabel");
    testSkillsInput = new wxTextCtrl(this, -1, "", wxPoint(100,360),
                                              wxSize(150,25), 0, wxDefaultValidator, "testSkillsInput");

    productBaseSkillsLabel = new wxStaticText(this, -1, "Product Skill:", wxPoint(10,410),
                                       wxDefaultSize, 0, "productBaseSkillsLabel");
    productBaseSkillsInput = new wxTextCtrl(this, -1, "", wxPoint(100,410),
                                     wxSize(150,25), 0, wxDefaultValidator, "productBaseSkillsInput");


    btnPlus = new wxButton(this, ID_PLUS, wxT("+"), wxPoint(10,510));
    exitButton = new wxButton(this, wxID_EXIT, wxT("Выход"), wxPoint(10, 560));


    btnPlus->Bind(wxEVT_BUTTON, &LeftPanel::OnPlus, this);
    exitButton->Bind(wxEVT_BUTTON, &LeftPanel::onExit, this);
    choiceStaffCategory->Bind(wxEVT_CHOICE, &LeftPanel::ChoiceStaffSelected, this);

    communicationSkillsLabel->Hide();
    communicationSkillsInput->Hide();
    testSkillsLabel->Hide();
    testSkillsInput->Hide();
    productBaseSkillsLabel->Hide();
    productBaseSkillsInput->Hide();

}

void LeftPanel::ChoiceStaffSelected(wxCommandEvent &event){
    wxChoice* choice = dynamic_cast<wxChoice*>(event.GetEventObject());
    if (choice) {
        int selectedIndex = choice->GetSelection();
        switch (selectedIndex) {
            case 0:
                systemSkillsLabel->Show();
                systemSkillsInput->Show();
                languageSkillsLabel->Show();
                languageSkillsInput->Show();
                dataBaseSkillsLabel->Show();
                dataBaseSkillsInput->Show();

                communicationSkillsLabel->Hide();
                communicationSkillsInput->Hide();
                testSkillsLabel->Hide();
                testSkillsInput->Hide();
                productBaseSkillsLabel->Hide();
                productBaseSkillsInput->Hide();
                break;
            case 1:
                systemSkillsLabel->Hide();
                systemSkillsInput->Hide();
                languageSkillsLabel->Hide();
                languageSkillsInput->Hide();
                dataBaseSkillsLabel->Hide();
                dataBaseSkillsInput->Hide();

                communicationSkillsLabel->Show();
                communicationSkillsInput->Show();
                testSkillsLabel->Show();
                testSkillsInput->Show();
                productBaseSkillsLabel->Show();
                productBaseSkillsInput->Show();
                break;
        }
    }
}

void LeftPanel::OnPlus(wxCommandEvent &event) {
    count++;

    StartWin *startWin = (StartWin *) parentPanel -> GetParent();
    startWin -> rightPanel -> textLabel -> SetLabel(wxString::Format(wxT("%d"), count));
    switch (choiceStaffCategory->GetSelection()){
        case 0:
            staffList.push_back(Developer(string(nameInput->GetLineText(0)),
                                          string(sernameInput->GetLineText(0)),
                                          string(patronymicInput->GetLineText(0)),
                                          string(employeList[employerList->GetSelection()]),
                                          datepicker->GetValue(),
                                         2, 4, 2));
            startWin->rightPanel->addStaff(staffList[staffList.size()-1].getSurname());
            sernameInput->SetValue("");
            nameInput->SetValue("");
            patronymicInput->SetValue("");
            break;
        case 1:
            staffList.push_back(Tester(string(nameInput->GetLineText(0)),
                                       string(sernameInput->GetLineText(0)),
                                       string(patronymicInput->GetLineText(0)),
                                       string(employeList[employerList->GetSelection()]),
                                       datepicker->GetValue(),
                                       7, 3, 1));
            startWin->rightPanel->addStaff(staffList[staffList.size()-1].getSurname());
            sernameInput->SetValue("");
            nameInput->SetValue("");
            patronymicInput->SetValue("");
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




