//
// Created by pbochkarev on 05.04.2023.
//

#include "Staff.h"
#include <iostream>
#include "Tester.h"
#include "Developer.h"

using namespace std;

void replaceEmployer(Staff employee, string newEmployer);
int main(){
    Staff x("Иван","Иванов","Иванович","ООО Зебра", "01.02.2022");
    cout << x.getName() << '\n';
    Tester y("Иван",
             "Иванов",
             "Иванович",
             "ООО Зебра",
             "01.02.2022",
             7, 3, 1);
    cout << y.getAverageGrade() << "\n";

    Developer mike("Михаил",
                   "Ливанов",
                   "Дмитриевич",
                   "ООО Лев",
                   "02.11.2015",
                   2, 4, 2);

    cout << "Средний бал разработчика " << mike.getName() << " = " << mike.getAverageGrade() << '\n';
    replaceEmployer(mike, "ООО Зебра");
}

void replaceEmployer(Staff employee, string newEmployer){
    cout << "Сотрудник: " << employee.getName() << " " << employee.getSurname() << " " << employee.getPatronymic()
                                                                                                                << "\n";
    cout << "Старое юр.лицо: " << employee.getEmployer() << "\n";
    employee.setEmployer(newEmployer);
    cout << "Новое юр.лицо: " << employee.getEmployer() << "\n";


}
