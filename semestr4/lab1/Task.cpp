//
// Created by pbochkarev on 14.02.2023.
//
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int i,k;
    int power(int,int);
    for(i=0; i<10; i++){
        k = power(2, i);
        printf("i = %d \nk = %d", i, k);
    }
}

int power(int x, int n){
    int i, p = 1;
    for(i=1; i<n; i++){
        p*=x;
    }
    return p;
}