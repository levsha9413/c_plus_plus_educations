//
// Created by pbochkarev on 05.04.2023.
//

#ifndef C_PLUS_PLUS_STAFF_H
#define C_PLUS_PLUS_STAFF_H

#include <string>
#include <wx/datetime.h>

using namespace std;

class Staff {
private:
    string name;
    string surname;
    string patronymic;
    string employer;
    wxDateTime startWork;
    wxString dateOfStartWork;
    int workExperience;

public:
    const string &getName() const;

    const string &getSurname() const;

    const string &getPatronymic() const;

    const string &getEmployer() const;

    const wxString &getDateOfStartWork() const;

    void setName(const string &name);

    void setSurname(const string &surname);

    void setPatronymic(const string &patronymic);

    void setEmployer(const string &employer);

    void setDateOfStartWork(const wxDateTime::wxDateTime_t day, const wxDateTime::Month month, const int year);

    Staff(const string &name, const string &surname, const string &patronymic, const string &employer,
          const wxDateTime::wxDateTime_t day, const wxDateTime::Month month, const int year);

    virtual float getAverageGrade() const{};

    const wxDateTime &getStartWork() const;

    int getWorkExperience();


};


#endif //C_PLUS_PLUS_STAFF_H
