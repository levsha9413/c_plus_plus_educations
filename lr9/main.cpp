//
// Created by pbochkarev on 18.04.2023.
//
#include "Money.h"
using namespace std;

template <class T>
void sort(T array[], ::size_t size){
    cout << "Запуск функции сортировки" << endl;
    T tmp;
        for (int i=0; i<size-1; i++) {
            for(int j = size-1; i<j; j--){
                if(array[i]>array[j]){
                    tmp = array[j];
                    array[j]=array[i];
                    array[i]=tmp;
                }
            }
    }
        cout << "Отсортированные элементы:" << endl;
        for (int i=0; i<size; i++) {
            cout << array[i] << "\n";
        }
        }

int main(){
    Money X(51.0, 21);
    Money Y(51, 11);
    cout << (X>Y) << endl;
    cout << X << " " << Y << endl;

    Money mas[] = {Money(14,51),
                   Money(14,21),
                   Money(1, 2),
                   Money(1,3)};

    sort(mas, size(mas));
    cout << "end";

}