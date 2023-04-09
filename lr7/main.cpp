//
// Created by pbochkarev on 05.04.2023.
//

#include "Staff.h"
#include <iostream>
#include <chrono>
#include "Tester.h"

using namespace std;

int main(){
    Staff x("Иван","Иванов","Иванович","ООО Зебра", "01.02.2022");
    cout << x.getName() << '\n';
    Tester y("Иван",
             "Иванов",
             "Иванович",
             "ООО Зебра",
             "01.02.2022",
             7, 3, 1);
    cout << y.getAverageGrade();


}