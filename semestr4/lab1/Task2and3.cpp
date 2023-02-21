//
// Created by pbochkarev on 20.02.2023.
//
#define PR(x) printf("x=%u, *x=%d, &x=%u\n", x,*x,&x)
#include <stdio.h>
#include <iostream>

using namespace std;


int main() {
    int mas[] = {100, 200, 300};
    int *ptr1, *ptr2; //int - 4 байта
    ptr1 = mas;
    ptr2 = &mas[1];
    PR(ptr1);
    PR(ptr2);
    ++ptr2;
    printf("ptr2-ptr1=%u\n", ptr2 - ptr1);
    printf("_____________________________________\nint:\n");
    int x = 10;
    int *px = &x;
    printf("px=%d\n", px); //адрес, где лежит значение x;
    printf("*px=%d\n", *px); //значение, доступное по этому адресу
    printf("&x=%d\n", &x); //ссылка на объект x, возвращает адрес объекта
    ++px;
    printf("px=%d\n", px);
    printf("*px=%d\n", *px);

    printf("_____________________________________\nfloat:\n"); //4 байта
    float y = 54.23;
    float *py = &y;//указывает на адрес памяти который возвращает &y
    printf("y=%f\n",y); //доступ к значению памяти
    printf("*py=%f\n", *py); //доступ к значению памяти
    printf("py=%d\n", py); //доступ к адресу
    printf("&y=%d\n",&y); //доступ к адресу
    ++py;
    printf("py=%d\n", py);
    printf("*py=%f\n", *py);

    printf("_____________________________________\nМассивы:\n");
    int numbers[] = {20,21,22,23,24,25};
    for(int *p = numbers, i = 0; i < 6; ++i, ++p){
        printf("*p=%d\n",*p);
    }

    printf("_____________________________________\nЗадание 3:\n");

    void obmen1(int,int);
    void obmen2(int*, int*);
    void obmen3(int&, int&);
    int a = 7;
    int b = 3;
    int *pa = &a;
    int *pb = &b;
    cout << "До обмена a = " << a << " b = " << b << endl;
    obmen1(a,b);
    cout << "a = " << a << " b = " << b << endl;
    obmen2(pa,pb);
    cout << "a = " << a << " b = " << b << endl;
    obmen3(a, b);
    cout << "a = " << a << " b = " << b << endl;

}

void obmen1(int a, int b){
    cout << "Выполняется обмен 1" << endl;
    int buffer = a;
    a = b;
    b = buffer;
}

void obmen2(int *a, int *b){
    cout << "Выполняется обмен 2" << endl;
    int buffer = *a;
    *a = *b;
    *b = buffer;
}

void obmen3(int &a, int &b){
    cout << "Выполняется обмен 3" << endl;
    int buffer = a;
    a = b;
    b = buffer;
}

