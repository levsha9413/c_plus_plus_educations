//
// Created by pbochkarev on 05.04.2023.
//

#include "Staff.h"

const string &Staff::getName() const {
    return name;
}

const string &Staff::getSurname() const {
    return surname;
}

const string &Staff::getPatronymic() const {
    return patronymic;
}

const string &Staff::getEmployer() const {
    return employer;
}

const wxString &Staff::getDateOfStartWork() const {
    return dateOfStartWork;
}

void Staff::setName(const string &name) {
    Staff::name = name;
}

void Staff::setSurname(const string &surname) {
    Staff::surname = surname;
}

void Staff::setPatronymic(const string &patronymic) {
    Staff::patronymic = patronymic;
}

void Staff::setEmployer(const string &employer) {
    Staff::employer = employer;
}

void Staff::setDateOfStartWork(wxDateTime date) {
    if(date.IsValid()){
        wxPuts("Valid : ");
    }else{
        wxPuts("No Valid : ");
    };
    Staff::startWork = date;
    Staff::dateOfStartWork = startWork.FormatDate();
}

Staff::Staff(const string &name, const string &surname, const string &patronymic, const string &employer,
             const wxDateTime date)
             : name(name), surname(surname), patronymic(patronymic), employer(employer),
               startWork(date) {
    Staff::setName(name);
    Staff::setSurname(surname);
    Staff::setPatronymic(patronymic);
    Staff::setEmployer(employer);
    Staff::setDateOfStartWork(date);


}

const wxDateTime &Staff::getStartWork() const {
    return startWork;
}

int Staff::getWorkExperience() {
    wxDateTime now = wxDateTime::Now();
    wxDateSpan range = now.DiffAsDateSpan(startWork);
    Staff::workExperience = range.GetTotalMonths();
    return workExperience;
}


