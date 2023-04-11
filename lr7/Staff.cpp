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

const string &Staff::getDateOfStartWork() const {
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

void Staff::setDateOfStartWork(const string &dateOfStartWork) {
    Staff::dateOfStartWork = dateOfStartWork;
}

Staff::Staff(const string &name, const string &surname, const string &patronymic, const string &employer,
             const string &dateOfStartWork) : name(name), surname(surname), patronymic(patronymic), employer(employer),
                                              dateOfStartWork(dateOfStartWork) {
    Staff::setName(name);
    Staff::setSurname(surname);
    Staff::setPatronymic(patronymic);
    Staff::setEmployer(employer);
    Staff::setDateOfStartWork(dateOfStartWork);


}


