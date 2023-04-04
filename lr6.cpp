//
// Created by pbochkarev on 04.04.2023.
//
#include "Text.h"

int main(){
    Text oldText = Text("abc");
    Text newText;
    newText = oldText;
    cout << "\nРезультат операции = \n";
    cout << "newText\n";
    newText.output();
    cout << "oldText\n";
    oldText.output();
    newText = newText + oldText;

    cout << "\nРезультат операции + \n";
    cout << "newText\n";
    newText.output();
    cout << "oldText\n";
    oldText.output();

    cout << "\nРезультат операции == \n";
    if(newText == oldText){
        cout << "Объекты равны\n";
    }else{
        cout << "Объекты НЕ равны\n";

    }

}
