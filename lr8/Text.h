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
    friend ostream& operator<<(ostream &os, const  Text& n);
    friend istream& operator>>(istream &is, Text& n);
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
        cout << "Деструктор выполнен\n";
    }
    Text& operator=(const Text& t) {
        this->length = t.getLength();
        if (str == NULL) {
        this->str = (char *) malloc(length);
        }

        char* p = t.getText();
        int index = 0;
        while (*p){
            str[index]=*p;
            ++p;
            ++index;
        }
        //str = t.getText(); //не работает
        return *this;
    }
    Text& operator+(const Text& t){
        this->length = this->length + t.getLength();
        char* p = this->getText();
        char* s = t.getText();
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
        return *this;

    }
    bool operator==(const Text& t){
        if(this->length != t.length){
            return this->length == t.length;
        }else{
            char* FirstStringPointer = this->getText();
            char* SecondStringPointer = t.getText();
            while (*FirstStringPointer){
                if(*FirstStringPointer > *SecondStringPointer){
                    //cout << "\n" << messageFirst << " > " << messageSecond << endl;
                    return false;
                } else if(*FirstStringPointer < *SecondStringPointer){
                    //cout << "\n" << messageFirst << " < " << messageSecond << endl;
                    return false;
                } else if(*FirstStringPointer == *SecondStringPointer){
                    ++FirstStringPointer;
                    ++SecondStringPointer;
                }
            }
            return true;
        }
    }

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
        cout << "Текстовое поле: " << str << "\n";
        cout << "Длина текста: " << length << "\n";
    }



};


