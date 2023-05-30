//
// Created by pbochkarev on 09.04.2023.
//

#ifndef C_PLUS_PLUS_DEVELOPER_H
#define C_PLUS_PLUS_DEVELOPER_H
#include "Staff.h"

class Developer : public Staff{
private:
    float systemSkills;
    float languageSkills;
    float dataBaseSkills;

public:
    Developer(const string &name, const string &surname, const string &patronymic, const string &employer,
              const wxDateTime::wxDateTime_t day, const wxDateTime::Month month, const int year,
              float systemSkills, float languageSkills, float dataBaseSkills);

    void setSystemSkills(float systemSkills);

    void setLanguageSkills(float languageSkills);

    void setDataBaseSkills(float dataBaseSkills);

    float getSystemSkills() const;

    float getLanguageSkills() const;

    float getDataBaseSkills() const;

    float getAverageGrade() const;

};


#endif //C_PLUS_PLUS_DEVELOPER_H
