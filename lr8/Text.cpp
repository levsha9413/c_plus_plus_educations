//
// Created by pbochkarev on 11.04.2023.
//

#include "Text.h"

ostream& operator<<(ostream &os, const  Text& n){
    os << n.str;
    return os;
}

istream& operator>>(istream &is,  Text& n){
    is >> n.str;
    return is;
}