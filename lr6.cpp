//
// Created by pbochkarev on 29.03.2023.
//
#include <iostream>
#include <stdlib.h>

using namespace std;

class Text{

private:
    char *str;
    int length;
public:
    Text(){
      length = 0;
      str = NULL;
    }
    Text(char message[]){
        int counter = 0;
        char* p = message;
        while(*p){
            ++p;
            ++counter;
        }
        str = (char*)malloc(counter);
        char *pointer = message;
        int index = 0;
        while (*pointer){
            str[index++]= message[index];
            ++pointer;
        }
        length = index;

    }
    Text(const Text& text){
    }
    ~Text(){
        free(str);
    }
    Text& operator=(const Text& t){
        length = t.getLength();
        str = t.getText(); //не работает
    }
    Text& operator+(const Text&);
    Text& operator==(const Text&);

     int getLength()const{
        return length;
    }
    char* getText() const{

        return str;
    }
    void input(){
        cout << "Введите текст:\n";
        cin >> str;
    }
    void output(){
        cout << "Содержимое объекта:\n";
        cout << str << "\n";
    }

};

int main(){
    Text x = Text("abc");
    char* s = x.getText();
    Text a;
    a = x;
    a.output();
}