//
// Created by pbochkarev on 06.06.2023.
//

#ifndef C_PLUS_PLUS_LEFTPANEL_H
#define C_PLUS_PLUS_LEFTPANEL_H
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/choice.h>
#include "../Staff.h"
#include "../Developer.h"
#include "../Tester.h"
#include <wx/textctrl.h>
#include <wx/stattext.h>
#include <wx/datectrl.h>


#include <vector>

class LeftPanel: public wxPanel{
public:
    LeftPanel(wxPanel *parent);

    wxButton *btnPlus;
    wxPanel *parentPanel;
    wxButton *exitButton;
    vector <Staff> staffList={};

    wxStaticText *nameLabel;
    wxTextCtrl *nameInput;
    wxStaticText *sernameLabel;
    wxTextCtrl *sernameInput;
    wxStaticText *patronymicLabel;
    wxTextCtrl *patronymicInput;
    wxStaticText *employerListLabel;
    wxChoice *employerList;
    wxStaticText *datepickerLabel;
    wxDatePickerCtrl *datepicker;
    wxStaticText *choiceStaffCategoryLabel;
    wxChoice *choiceStaffCategory;

    //Поля навыков Developer
    wxStaticText *systemSkillsLabel;
    wxTextCtrl *systemSkillsInput;
    wxStaticText *languageSkillsLabel;
    wxTextCtrl *languageSkillsInput;
    wxStaticText *dataBaseSkillsLabel;
    wxTextCtrl *dataBaseSkillsInput;

    //Поля навыков Tester
    wxStaticText *communicationSkillsLabel;
    wxTextCtrl *communicationSkillsInput;
    wxStaticText *testSkillsLabel;
    wxTextCtrl *testSkillsInput;
    wxStaticText *productBaseSkillsLabel;
    wxTextCtrl *productBaseSkillsInput;




private:
    int count;
    void OnPlus(wxCommandEvent &event);
    void OnMinus(wxCommandEvent &event);
    void onExit(wxCommandEvent &event);
    void ChoiceStaffSelected(wxCommandEvent &event);
    wxArrayString staffCategoryes;
    wxArrayString employeList;

};


#endif //C_PLUS_PLUS_LEFTPANEL_H
