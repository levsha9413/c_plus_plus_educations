//
// Created by pbochkarev on 06.06.2023.
//

#include "RightPanel.h"


RightPanel::RightPanel(wxPanel *parent) :
    wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(270,1000), wxBORDER_SUNKEN) {
    textLabel = new wxStaticText(this, 1, wxT("0"), wxPoint(40,100));
    listOfStaff = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxSize(270,150), 0,
                                NULL, wxLB_HSCROLL,
                                wxDefaultValidator, "List of Staff");



}

void RightPanel::addStaff(wxString staff) {
    staffArray.Add(staff);
    listOfStaff->InsertItems(staffArray, 0);
    staffArray.Clear();
};

