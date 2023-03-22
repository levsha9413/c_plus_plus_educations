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
#include <chrono>


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
        while (getline(input, line, char(0))) { //0 - NULL символ, чтобы прочитал весь файл
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

void SubstringFinder(string path){
    ofstream outputFile("rezult.txt");
    time_t real_time = chrono::system_clock::to_time_t(chrono::system_clock::now());
    outputFile << "Created at " << ctime(&real_time); //перезаписали временем
    outputFile.setf(ios::app); //переключили в режим дозаписи

    cout << "Введите искомую строку:\n";
    string substring;
    cin >> substring;
    outputFile << "Искомая строка: " << substring << endl;
    outputFile << "Файл поиска: " << path << endl;
    ifstream input(path);
    string line;
    int numberOfString = 1;
    int coincidence = 0;
    if(input){
        while(getline(input, line)){ //взятие отдельной строки
            int index = 0;
            while((index = line.find(substring, index)) != std::string::npos) { //поиск подстроки в строкe
                ++coincidence;
                outputFile << "Совпадение №" << coincidence  <<  ": Строка " << numberOfString << " \" | " << line << "\""
                << " Индекс вхождения: " << index << endl;
                index += substring.length();

            }
            ++numberOfString;
        }
        outputFile << "-----------------------\nВсего найдено вхождений: " << coincidence << endl;
    }else{
        cout << "File opening error" << endl;
    }
}

void CreateFileForTaskFour(string srcPath, string dstFileName, int countOfString){
    ifstream inputFile(srcPath);
    ofstream rezultFile("../"+dstFileName );
    string line;
    int numberOfString = 1;
    if (inputFile) {
        while (countOfString--){
            getline(inputFile, line, char(0));
            rezultFile << "-" << numberOfString++ << "-\n" << line << "\f\n\n";
        }
    }
}

int main() {
//    string pathOfFile = "../hello.txt";
//    //readFromFile(pathOfFile);
//    //writeToEndOfFile(pathOfFile, 3);
//    SymbolCounter(pathOfFile);
//    SubstringFinder(pathOfFile);
    CreateFileForTaskFour("../src", "rezult", 5);
}
