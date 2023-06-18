//
// Created by pbochkarev on 09.04.2023.
//

#include "Developer.h"
#include <sstream>
#include <iomanip>
#include <cmath>

Developer::Developer(const string &name, const string &surname, const string &patronymic, const string &employer,
                     const wxDateTime date,
                     float systemSkills, float languageSkills, float dataBaseSkills)
        : Staff(name, surname, patronymic, employer, date), systemSkills(systemSkills),
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

string Developer::getAverageGrade() const {
    float avg = (Developer::getSystemSkills()+Developer::getDataBaseSkills()+Developer::getLanguageSkills())/3;
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << round(avg*10)/10;
    std::string result = ss.str();
    return result;
}
