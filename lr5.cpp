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
#include <regex>
#include <stdio.h>


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
            rezultFile << "-" << numberOfString++ << "-\n" << line << "\f\n";
        }
    }
}



void test(string srcPath){
    fstream file(srcPath);
    file.seekg(1, ios::beg);
    file.put(NULL);
    string numbers = "0123456789f\fhhHHHH\f";
    int x = numbers.find('\f');
    cout << x++ << endl;
    cout << numbers.find('\f', x);
    reverse(srcPath.begin(), srcPath.end());
    string newFileNAme =  srcPath;
    //rename(srcPath.c_str(), "old");

}

string PathWithOldLabels(string srcPath){
    reverse(srcPath.begin(), srcPath.end());
    string strPathWithOldLabels;
    if (srcPath.find('.') != std::string::npos & srcPath.find('.') < srcPath.length()-2) {
        string format = srcPath.substr(0, srcPath.find('.'));
        string baseName=srcPath.substr(srcPath.find('.')+1, srcPath.length());;
        reverse(format.begin(), format.end());
        reverse(baseName.begin(), baseName.end());
        cout << "format = " << format << endl;
        cout << "baseName = " << baseName << endl;
        strPathWithOldLabels = baseName + "_old." + format;
        cout << "strPathWithOldLabels = " << strPathWithOldLabels << endl;
    }
    else {
        reverse(srcPath.begin(), srcPath.end());
        strPathWithOldLabels = srcPath + "_old";
        cout << "strPathWithOldLabels = " << strPathWithOldLabels << endl;
    }
    return strPathWithOldLabels;
}

void ReverseNumberOfList(string srcPath){
    string srcPath_old = PathWithOldLabels(srcPath);
    rename(srcPath.c_str(), srcPath_old.c_str());
    ifstream input(srcPath_old);
    ofstream output(srcPath, ios::app);
    string line;
    cmatch result;
    regex regular("([\\n]?-)""([\\d]+)""(-\\n)""([.|\\s|\\w|\\S|\\W]*)");

    if (input) {  //если поток открылся без ошибок, то true
            while (getline(input, line, '\f')) {
                if(regex_match(line.c_str(), result, regular)) {
                    cout << "Регулярка отработала" << endl;
                    for(int i = 0; i< result.size(); ++i){
                    cout << "I= " << i << " result: " << result[i] << endl;
                }
                    output << result[4] << '\n' << result[2] << "\n\f\n";

            }else{
                    cout << "\nРегулярка не сработала\n";
                }
        }
    }

/*
 Можно посимвольно записывать или стирать в файл, но как узнать положение символа в который нужно писать.
 Положение можно узнать с помощью string.find(substing, start_index)
 1.Переименовываем файл в *_old
 2.Создаем новый файл new c именем исходного
 3.Вычитываем из old первую страницу
 4.Парсим первую страницу регуляркой разбивая на объекты
 5.Записываем в новый файл все объекты кроме номера
 6.Отступаем от конца файла 1 байт (\f) и записываем туда номер + \f
 */
}

int main() {
//    string pathOfFile = "../hello.txt";
//    //readFromFile(pathOfFile);
//    //writeToEndOfFile(pathOfFile, 3);
//    SymbolCounter(pathOfFile);
//    SubstringFinder(pathOfFile);
//    CreateFileForTaskFour("../src", "rezult", 5);
    CreateFileForTaskFour("../src", "test.txt", 5);

    // ReverseNumberOfList("../rezult");
    ReverseNumberOfList("../test.txt");
}
