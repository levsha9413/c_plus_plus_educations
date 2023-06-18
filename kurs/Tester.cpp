//
// Created by pbochkarev on 09.04.2023.
//
#include <iomanip>
#include "Tester.h"
#include <sstream>


void Tester::setCommunication(int communication) {
    Tester::communication = communication;
}

void Tester::setTestSkills(int testSkills) {
    Tester::testSkills = testSkills;
}

void Tester::setProductSkills(int productSkills) {
    Tester::productSkills = productSkills;
}

int Tester::getCommunication() const {
    return communication;
}

int Tester::getTestSkills() const {
    return testSkills;
}

int Tester::getProductSkills() const {
    return productSkills;
}

string Tester::getAverageGrade() const{
   float avg =  (Tester::communication + Tester::productSkills + Tester::getTestSkills())/3;
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << round(avg*10)/10;
    std::string result = ss.str();
    return result;
}

Tester::Tester(const string &name, const string &surname, const string &patronymic, const string &employer,
               const wxDateTime date,
               float _communication, float _testSkills, float _productSkills) :
        Staff(name, surname, patronymic, employer, date) {
   Tester::setCommunication(_communication);
   Tester::setTestSkills(_testSkills);
   Tester::setProductSkills(_productSkills);

};
