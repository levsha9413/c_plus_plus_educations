//
// Created by pbochkarev on 05.04.2023.
//

#ifndef C_PLUS_PLUS_STAFF_H
#define C_PLUS_PLUS_STAFF_H

#include <string>

using namespace std;

class Staff {
private:
    string name;
    string surname;
    string patronymic;
    string employer;
    string dateOfStartWork;
public:
    const string &getName() const;

    const string &getSurname() const;

    const string &getPatronymic() const;

    const string &getEmployer() const;

    const string &getDateOfStartWork() const;

    void setName(const string &name);

    void setSurname(const string &surname);

    void setPatronymic(const string &patronymic);

    void setEmployer(const string &employer);

    void setDateOfStartWork(const string &dateOfStartWork);

    Staff(const string &name, const string &surname, const string &patronymic, const string &employer,
          const string &dateOfStartWork);

    virtual float getAverageGrade() const{};



};


#endif //C_PLUS_PLUS_STAFF_H
