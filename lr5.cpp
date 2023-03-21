//
// Created by pbochkarev on 21.03.2023.
//
/*
 istream - поток ввода (cin) >> ifstream - чтение файла
 ostream - поток вывода (cout) >> ofstream - для записи
 iostream - поток ввода/вывода >> fstream - для записи и чтения
 getline - построчное чтение данных из потока, возвращает ссылку на поток
 >> - аналог считывания -> input >> myInt;
 input.ignore(1) - пропустить 1 символ;
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void readFromFile(string path){
    ifstream input(path);
    string line;
    if (input) {  //если поток открылся без ошибок, то true
        while (getline(input, line )) {
            cout << line << endl;
        }
        cout << "End of file" << endl;
    }else{
        cout << "error" << endl;
    }
}

void writeToEndOfFile(string path){
    ofstream output(path);

}

int main() {
    string pathOfFile = "../hello.txt";
    readFromFile(pathOfFile);
}

