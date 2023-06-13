//
// Created by pbochkarev on 06.06.2023.
//

#include "RightPanel.h"
#include "StartWin.h"



RightPanel::RightPanel(wxPanel *parent) :
    wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(270,1000), wxBORDER_SUNKEN) {
    textLabel = new wxStaticText(this, 1, wxT("0"), wxPoint(40,100));
    listOfStaff = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxSize(270,150), 0,
                                NULL, wxLB_HSCROLL,
                                wxDefaultValidator, "List of Staff");

    listOfStaff->Bind(wxEVT_LISTBOX_DCLICK, &RightPanel::clickOnStaff, this);


}

void RightPanel::addStaff(wxString staff) {
    staffArray.Add(staff);
    listOfStaff->InsertItems(staffArray, 0);
    staffArray.Clear();
}

void RightPanel::clickOnStaff(wxCommandEvent& event) {
    StartWin *startWin = (StartWin *) parentPanel -> GetParent();

    wxPuts("dddd");
    FormWin *StaffCard = new FormWin(this, wxID_ANY, "test", wxPoint(10,10), wxDefaultSize,
                                     wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER, "Dialog",
                                     startWin->leftPanel->staffList[listOfStaff->GetSelection()]);
    StaffCard->Show(true);
}



