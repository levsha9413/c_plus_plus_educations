//
// Created by pbochkarev on 21.02.2023.
//
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <stdio.h>

using namespace std;


int main() {
    int N = 5;
    float matrix[N][N];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matrix[i][j] = rand()/10.;
        }
    }
    //вывод
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << setw(8) << setprecision(5) << matrix[i][j] <<  " | ";
        }
        cout << endl;
    }

    float minMatrix = matrix[N-1][N-1];
    float maxMatrix = matrix[0][0];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (matrix[i][j] < minMatrix){
                    minMatrix = matrix[i][j];
            }
            if(matrix[i][j] > maxMatrix){
                maxMatrix = matrix[i][j];
            }
        }
    }
    cout << "Mинимум матрицы: " << minMatrix << endl;
    cout << "Максимум матрицы: " << maxMatrix << endl;

    cout << "\n_________Верхнеуголная часть:_________" << endl;
    float minVTMatrix = matrix[0][0];
    float maxVTMatrix = matrix[0][0];
    float summVT=0;
    int counterVT=0;
    for (int i = 0; i < N; ++i) { //строка
        for (int j = i; j < N; ++j) { //столбцы
            if (matrix[i][j] < minVTMatrix){
                minVTMatrix = matrix[i][j];
            }
            if(matrix[i][j] > maxVTMatrix){
                maxVTMatrix = matrix[i][j];
            }
            summVT+=matrix[i][j];
            ++counterVT;
        }
    }
    float averageVT = summVT/counterVT;
    cout << "Mинимум верхнеугольной части матрицы: " << minVTMatrix << endl;
    cout << "Максимум верхнеугольной части матрицы: " << maxVTMatrix << endl;
    cout << "Сумма элементов верхнеугольной части матрицы: " << summVT << endl;
    cout << "Среднее арифметическое значение элементов верхнетреугольной части: " << averageVT << endl;




    cout << "\n_________Нижнеуголная часть:_________" << endl;
    float minNTMatrix = matrix[0][0];
    float maxNTMatrix = matrix[0][0];
    float summNT=0;
    int counterNT=0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (matrix[i][j] < minVTMatrix){
                minNTMatrix = matrix[i][j];
            }
            if(matrix[i][j] > maxNTMatrix){
                maxNTMatrix = matrix[i][j];
            }
            summNT+=matrix[i][j];
            ++counterNT;
        }
    }
    float averageNT = summNT/counterNT;
    cout << "Mинимум нижнеугольной части матрицы: " << minNTMatrix << endl;
    cout << "Максимум нижнеугольной части матрицы: " << maxNTMatrix << endl;
    cout << "Сумма элементов нижнеугольной части матрицы: " << summVT << endl;
    cout << "Среднее арифметическое значение элементов нижнетреугольной части:"<< averageNT << endl;



    cout << "\n_________Главная диагональ:_________" << endl;
    float minMainD = matrix[0][0];
    float maxMainD = matrix[0][0];
    for (int i = 0; i < N; ++i) {
            if (matrix[i][i] < minMainD){
                minMainD = matrix[i][i];
            }
            if(matrix[i][i] > maxMainD) {
                maxMainD = matrix[i][i];
            }
    }
    cout << "Mинимум главной диагонали матрицы: " << minMainD << endl;
    cout << "Максимум главной диагонали матрицы: " << maxMainD << endl;

    cout << "\n_________Побочная диагональ:_________" << endl;
    float minSlaveD = matrix[0][N-1];
    float maxSlaveD = matrix[0][N-1];
    for (int i = 0; i < N; ++i) {
        if (matrix[i][N-1-i] < minSlaveD){
            minSlaveD = matrix[i][N-1-i];
        }
        if(matrix[i][N-1-i] > maxSlaveD) {
            maxSlaveD = matrix[i][N-1-i];
        }
    }
    cout << "Mинимум побочной диагонали матрицы: " << minSlaveD << endl;
    cout << "Максимум побочной диагонали матрицы: " << maxSlaveD << endl;

    cout << "\n_________Среднее арифметическое значение элементов матрицы:_________" << endl;
    float summ = 0;
    int counter=0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            summ += matrix[i][j];
            ++counter;
        }
    }
    float averageMatrix = summ/counter;
    cout << averageMatrix <<endl;

    cout<<"__________________Работа со строками___________________________"<<endl;

    float summString=0;
    int counterString=0;
    float averageString;

    for (int i = 0; i < N; ++i) {
        float min = matrix[i][0];
        float max = matrix[i][0];
        for (int j = 0; j < N; ++j) {
            summString+=matrix[i][j];
            ++counterString;
            if(matrix[i][j]<min){
                min = matrix[i][j];
            }
            if(matrix[i][j]>max){
                max = matrix[i][j];
            }
        }
        cout << "Сумма элементов строки " << i << " : " << summString << endl;
        cout << "Среднее арифметическое строки " << i << " : " << summString/counterString << endl;
        cout << "Наибольший элемент строки " << i << " : " << max << endl;
        cout << "Наименьший элемент строки " << i << " : " << min << "\n" << endl;
    }
    cout<<"__________________Работа со столбцами___________________________"<<endl;
    float summColumn=0;
    int counterColumn=0;
    float averageColumn;


    for (int j = 0; j < N; ++j) { //выбрали столбец
        float min = matrix[j][0];
        float max = matrix[j][0];
        for (int i = 0; i < N; ++i) { //выбрали строку
            summColumn += matrix[i][j];
            ++counterColumn;
            if (matrix[i][j] < min) {
                min = matrix[i][j];
            }
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
        cout << "Сумма элементов столбца " << j << " : " << summString << endl;
        cout << "Среднее арифметическое столбца " << j << " : " << summString / counterString << endl;
        cout << "Наибольший элемент столбца " << j << " : " << max << endl;
        cout << "Наименьший элемент столбца " << j << " : " << min << "\n" << endl;
    }

    cout << "Элемент матрицы, минимально отличающийся от среднего арифметического:" << endl;
    float minDiff = matrix[0][0]-averageMatrix;
    float minDiffElem = NULL;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (abs(matrix[i][j] - averageMatrix) < abs(minDiff)){
                minDiff = abs(matrix[i][j] - averageMatrix);
                minDiffElem = matrix[i][j];
            }

        }
    }
    cout << minDiffElem << endl;

}
