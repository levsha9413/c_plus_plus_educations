//
// Created by pbochkarev on 18.04.2023.
//
#include <iostream>
#ifndef C_PLUS_PLUS_MONEY_H
#define C_PLUS_PLUS_MONEY_H
using namespace std;

class Money {
private:
    long dollars;
    int cents;
public:
    Money(int _dollars, int _cents);
    Money();
    int operator>(const Money&) const;
    friend ostream& operator <<(ostream&, Money&);
};


#endif //C_PLUS_PLUS_MONEY_H
