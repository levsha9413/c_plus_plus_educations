//
// Created by pbochkarev on 14.03.2023.
//
#include <iostream>
#include <string>

using namespace std;

int LenghtStringByLoop(char message[]){
    int counter = 0;
    char* p = message;
    while(*p){
        ++p;
        ++counter;
    }
    return counter;
}
int LenghtStringByLoopSecondMethod(char message[]){
    int counter = 0;
    char* start = message;
    char* end = start;
    while(*end){
        ++end;
    }
    return end - start;
}
int LenghtStringByLoopThirdMethod(char message[]){
    int counter = 0;
    while(message[++counter]){
    }
    return counter;
}

void CopyString(char message[]){
    char copyString[256];
    ::strcpy(copyString,message);
    cout << "\n\n\n Использование функций strcpy.\nИсходная строка:\n" << message << "\nКопия:\n" << copyString;
}

void CopyStringManual(char message[]){
    char copyString[LenghtStringByLoop(message)]; //не через sizeof, потому что он считает размер от указателя на char[]
    char* p = message;
    int index = 0;
    while (*p){
        copyString[index++]= message[index];
        ++p;
    }
    cout << "CopyStringManual: " << copyString;
}

void ConcatinationString(char messageFirst[], char messageSecond[]){

    cout << "\nКонкатенация функцией strcat:\nстрока 1: " << messageFirst << "\nстрока 2: " << messageSecond;
    strcat(messageFirst, messageSecond);
    cout << "\nРезультат конкатенации: " << messageFirst;
}

void ConcatinationStringManual(char messageFirst[], char messageSecond[]){

    cout << "\nКонкатенация функцией ConcatinationStringManual:\nстрока 1: " << messageFirst << "\nстрока 2: " << messageSecond;
    char* p = messageFirst;
    char* s = messageSecond;
    while(*p){
        ++p;
    }
    while(*s){
        *p=*s;
        ++p;
        ++s;
    }
    ++p;
    *p='\0';

    cout << "\nРезультат конкатенации: " << messageFirst;
}


void LenghtStrlen(char message[]){
    cout << "Полученная строка: \n" << message << endl;
    cout << "\nДлинна строки, подсчитанная функцией strlen "<< " составляет " << ::strlen(message);
    cout << "\nДлинна строки, подсчитанная функцией LenghtStringByLoop "
    << " составляет " << LenghtStringByLoop(message);
    cout << "\nДлинна строки, подсчитанная функцией LenghtStringByLoopSecondMethod "
    << " составляет " << LenghtStringByLoopSecondMethod(message);
    cout << "\nДлинна строки, подсчитанная функцией LenghtStringByLoopThirdMethod "
         << " составляет " << LenghtStringByLoopThirdMethod(message);
}



int main(){
    char text[256];
    cout << "Введите строку:" << endl;
    cin >> text;
    LenghtStrlen(text);
    CopyString(text);
    cout << "\n__________________________________________\n";
    CopyStringManual(text);
    cout << "\n__________________________________________\n";
    cout << "Конкатенация строк\n";
    char stringFirst[256];
    char stringSecond[256];
    cout << "Введите строку 1 и строку 2:\n";
    cin >> stringFirst >> stringSecond;
    //ConcatinationString(stringFirst, stringSecond);
    ConcatinationStringManual(stringFirst, stringSecond);
    //Остановился на сравнении строк

}

