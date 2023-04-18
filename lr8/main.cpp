//
// Created by pbochkarev on 11.04.2023.
//
#include "Text.h"
#include <iostream>
#include <fstream>

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

void writeToEndOfFileWithAte(string path, int copy) {
    fstream output(path, ios::ate | ios::in);
    cout<< "Позиция указателя: " << output.tellg() << "\n";
    output.setf(ios::out);
    while (copy--) {
        output << "AtE\n";
    }
    cout<< "Позиция указателя: " << output.tellg() << "\n";
    output.close();
    fstream x(path, ios::ate | ios::in);
    cout<< "Позиция указателя: " << x.tellg() << "\n";
}

void readFromBinFile(string path){
    ifstream input(path, ios::binary);
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

void readToEndOfFileTrunc(string path) {
    fstream output(path,  ios::out | ios::trunc);

}

int main(){

    Text oldText = Text("abc");
    cout << oldText << endl;
    cout << "Введите строку для объекта: \n";
    cin >> oldText;
    cout << oldText << endl;

    string pathOfFile = "../lr8/hello.txt";
    readFromFile(pathOfFile);
    writeToEndOfFile(pathOfFile, 3);
    writeToEndOfFileWithAte(pathOfFile, 3);
    readFromBinFile("../lr8/hello_encrypted");
    readToEndOfFileTrunc(pathOfFile);




}
