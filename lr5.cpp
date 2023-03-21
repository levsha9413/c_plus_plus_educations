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
        while (getline(input, line, ' ' )) {
            cout << line << endl;
        }
        cout << "End of file" << endl;
    }else{
        cout << "error" << endl;
    }
}

void writeToEndOfFile(string path, int copy) {
    ofstream output(path, ios::app); //app - добавить в конец файла
    while (copy--) {
        output << "\nhello" << endl;
    }
}

void SymbolCounter(string path){
    ifstream input(path);
    string line;
    int visibleSymbolCounter = 0;
    int escapeSymbolCounter = 0;
    if (input) {  //если поток открылся без ошибок, то true
        while (getline(input, line, char(0))) {
            char symbols[line.size()];
            strcpy(symbols, line.c_str());
            for(auto symbol:symbols){
                if(int(symbol)<33){
                    ++escapeSymbolCounter;
                }else{
                    ++visibleSymbolCounter;
                }
            }
        }
        cout << "__Function SymbolCounter__" << endl;
        cout << "Path to file: " << path << endl;
        cout << "Visible symbols: " << visibleSymbolCounter << endl;
        cout << "Escape symbols: " << escapeSymbolCounter << endl;
    }else{
        cout << "error" << endl;
    }
}

int main() {
    string pathOfFile = "../hello.txt";
    //readFromFile(pathOfFile);
    //writeToEndOfFile(pathOfFile, 3);
    SymbolCounter(pathOfFile);
}
