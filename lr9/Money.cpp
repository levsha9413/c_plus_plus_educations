//
// Created by pbochkarev on 18.04.2023.
//

#include "Money.h"

Money::Money(int _dollars, int _cents)  {
    dollars = _dollars;
    cents = _cents;
}

Money::Money(){}

int Money::operator>(const Money& amt) const {
    return (dollars > amt.dollars) || (dollars == amt.dollars && cents > amt.cents);
}

ostream& operator <<(ostream& os, Money& M){
    return os << "$" << M.dollars << '.' << M.cents;
}
