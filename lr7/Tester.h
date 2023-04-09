//
// Created by pbochkarev on 09.04.2023.
//

#ifndef C_PLUS_PLUS_TESTER_H
#define C_PLUS_PLUS_TESTER_H

#include "Staff.h"


class Tester : public Staff{
private:
    float communication = 5;
    float testSkills = 3;
    float productSkills = 3;
public:
    Tester(const string &name, const string &surname, const string &patronymic, const string &employer,
           const string &dateOfStartWork, float _communication, float _testSkills, float _productSkills);

    void setCommunication(int communication);

    void setTestSkills(int testSkills);

    void setProductSkills(int productSkills);

    int getCommunication() const;

    int getTestSkills() const;

    int getProductSkills() const;

    float getAverageGrade() const;
};


#endif //C_PLUS_PLUS_TESTER_H
