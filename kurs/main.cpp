//
// Created by pbochkarev on 05.04.2023.
//

#include "Staff.h"
#include <iostream>
#include "Tester.h"
#include "Developer.h"
#include <wx/string.h>
#include <wx/crt.h>


using namespace std;

void replaceEmployer(Staff employee, string newEmployer);

int main(){
    wxPuts("ппп");
    wxString d = wxT("tomorrow");

    wxDateTime startWork = wxDateTime();
    wxDateTime::wxDateTime_t day = 12;
    wxDateTime::Month month = wxDateTime::Month::Jan;
    startWork.Set(day, month, 2022);
    wxString date = startWork.Format();
    wxPuts("date: " + date + "\n");
    wxDateTime now = wxDateTime::Now();
    wxDateSpan range = now.DiffAsDateSpan(startWork);
    int moths = range.GetTotalMonths();
    cout << moths << endl;



    Tester ivan("Иван",
             "Иванов",
             "Иванович",
             "ООО Зебра",
             wxDateTime::wxDateTime_t(12),
             wxDateTime::Month(wxDateTime::Jan),
             2022,
             7, 3, 1);
    cout << ivan.getAverageGrade() << "\n";

    Developer mike("Михаил",
                   "Ливанов",
                   "Дмитриевич",
                   "ООО Лев",
                   wxDateTime::wxDateTime_t(12),
                   wxDateTime::Month(wxDateTime::Jan),
                   2023,
                   2, 4, 2);

    cout << "Средний бал разработчика " << mike.getName() << " = " << mike.getAverageGrade() << '\n';
    replaceEmployer(mike, "ООО Зебра");
    replaceEmployer(ivan, "ООО КИТ");

    cout << "Стаж разработчика " << mike.getName() << " = " << mike.getWorkExperience() << " месяцев\n";
    cout << "Стаж разработчика " << ivan.getName() << " = " << ivan.getWorkExperience() << " месяцев\n";
    wxPuts(ivan.getDateOfStartWork());



}

void replaceEmployer(Staff employee, string newEmployer){
    cout << "Сотрудник: " << employee.getName() << " " << employee.getSurname() << " " << employee.getPatronymic()
                                                                                                                << "\n";
    cout << "Старое юр.лицо: " << employee.getEmployer() << "\n";
    employee.setEmployer(newEmployer);
    cout << "Новое юр.лицо: " << employee.getEmployer() << "\n";


}
