//
// Created by pbochkarev on 09.04.2023.
//

#include "Developer.h"

Developer::Developer(const string &name, const string &surname, const string &patronymic, const string &employer,
                     const wxDateTime::wxDateTime_t day, const wxDateTime::Month month, const int year,
                     float systemSkills, float languageSkills, float dataBaseSkills)
        : Staff(name, surname, patronymic, employer, day, month, year), systemSkills(systemSkills),
          languageSkills(languageSkills), dataBaseSkills(dataBaseSkills) {

}

void Developer::setSystemSkills(float systemSkills) {
    Developer::systemSkills = systemSkills;
}

void Developer::setLanguageSkills(float languageSkills) {
    Developer::languageSkills = languageSkills;
}

void Developer::setDataBaseSkills(float dataBaseSkills) {
    Developer::dataBaseSkills = dataBaseSkills;
}

float Developer::getSystemSkills() const {
    return systemSkills;
}

float Developer::getLanguageSkills() const {
    return languageSkills;
}

float Developer::getDataBaseSkills() const {
    return dataBaseSkills;
}

float Developer::getAverageGrade() const {
    return (Developer::getSystemSkills()+Developer::getDataBaseSkills()+Developer::getLanguageSkills())/3;
}
