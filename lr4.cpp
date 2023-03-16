//
// Created by pbochkarev on 14.03.2023.
//
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>


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
void CopyStringManualMalloc(char message[]){
    char *copyString;
    copyString = (char*)malloc(LenghtStringByLoop(message));
    char *p = message;
    int index = 0;
    while (*p){
        copyString[index++]= message[index];
        ++p;
    }
    cout << "\nCopyStringManualMalloc: " << copyString;
    free(copyString);
    cout << "\nCopyStringManualMalloc после free: " << copyString;

}
void CopyStringManualCalloc(char message[]){
    char *copyString;
    copyString = (char*)calloc(LenghtStringByLoop(message), sizeof(char));
    //указатель указывает на область заполненную нулями
    //удобно использовать при работе с массивами
    char *p = message;
    int index = 0;
    while (*p){
        copyString[index++]= message[index];
        ++p;
    }
    cout << "\nCopyStringManualCalloc: " << copyString;
    free(copyString);
    cout << "\nCopyStringManualCalloc после free: " << copyString;

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


void StringCompare(char messageFirst[], char messageSecond[]){
    cout << "\nРазница строк функцией strcmp():\nстрока 1: " << messageFirst << "\nстрока 2: " << messageSecond;
    int diff = strcmp(messageFirst, messageSecond);
    if(diff > 0){
        cout << "\n" << messageFirst << " > " << messageSecond << endl;
    }else if(diff < 0){
        cout << "\n" << messageFirst << " < " << messageSecond << endl;

    }else if(diff == 0){
        cout << "\n" << messageFirst << " = " << messageSecond << endl;
    }
}
void StringCompareManual(char messageFirst[], char messageSecond[]) {
    cout << "\nРазница строк функцией StringCompareManual:\nстрока 1: " << messageFirst << "\nстрока 2: " << messageSecond;
    char* FirstStringPointer = messageFirst;
    char* SecondStringPointer = messageSecond;
    while (*FirstStringPointer){
        if(*FirstStringPointer > *SecondStringPointer){
            cout << "\n" << messageFirst << " > " << messageSecond << endl;
            return;
        } else if(*FirstStringPointer < *SecondStringPointer){
            cout << "\n" << messageFirst << " < " << messageSecond << endl;
            return;
        } else if(*FirstStringPointer == *SecondStringPointer){
            ++FirstStringPointer;
            ++SecondStringPointer;
        }
    }
    if(strlen(messageFirst)==strlen(messageSecond)){
        cout << "\n" << messageFirst << " == " << messageSecond << endl;
    } else if(strlen(messageFirst) < strlen(messageSecond)){
        cout << "\n" << messageFirst << " < " << messageSecond << endl;
    }
}

int main(){
    char text[256];
    cout << "Введите строку:" << endl;
    cin >> text;
    LenghtStrlen(text);
    CopyString(text);
    cout << "\n__________________________________________\n";
    CopyStringManual(text);
    CopyStringManualMalloc(text);
    CopyStringManualCalloc(text);

    cout << "\n__________________________________________\n";
    cout << "Конкатенация строк\n";
    char stringFirst[256];
    char stringSecond[256];
    cout << "Введите строку 1 и строку 2:\n";
    cin >> stringFirst >> stringSecond;
    //ConcatinationString(stringFirst, stringSecond);
    //ConcatinationStringManual(stringFirst, stringSecond);
    StringCompare(stringFirst, stringSecond);
    StringCompareManual(stringFirst, stringSecond);

    vector <string> Strings = {"apple","orange","onion"};
    for(auto word : Strings){
        char str[sizeof(word)/ sizeof(char)];
        strcpy (str, word.c_str());
        CopyStringManualCalloc(str);
    }
}

