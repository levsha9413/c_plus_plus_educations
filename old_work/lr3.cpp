#include <iostream>
#include <vector>

using namespace std;

void printMass(vector <int> mas){
    for(auto x : mas){
        cout << x << " | ";
    }
    cout << endl;
}

void BubbleSort(vector<int>& mas){
   auto sortMass = mas;
   for(int elem=0; elem<mas.size()-1; ++elem){
       for(int i=elem+1; i<mas.size(); ++i){
           if (mas[elem]>mas[i]){
               int buffer = mas[i];
               mas[i]=mas[elem];
               mas[elem]=buffer;
           }
       }
   }
}

void QuickSort(vector<int>& mas, int startIndex, int endIndex){
    if(startIndex<endIndex){
        int supportElement = mas[(startIndex+endIndex)/2];
        int leftReplaceElement = startIndex;
        int rightReplaceElement = endIndex;
        do{
            while(mas[leftReplaceElement]<supportElement){ //крутим пока не найдем элемент для замены, слева от опорного
                leftReplaceElement++;
            }
            while (mas[rightReplaceElement]>supportElement){ //крутим пока не найдем элемент для замены, справа от опорного
                rightReplaceElement--;
            }
            if(leftReplaceElement<=rightReplaceElement){ //проверяем что не заехали друг на друга
                int buffer = mas[leftReplaceElement];
                mas[leftReplaceElement] = mas[rightReplaceElement]; //меняем местами найденные элементы
                mas[rightReplaceElement] = buffer;
                --rightReplaceElement; //увеличиваем индексы для след итерации
                ++leftReplaceElement;
            }
        } while (leftReplaceElement<rightReplaceElement); //проверяем что не заехали друг на друга
        QuickSort(mas, startIndex, rightReplaceElement);
        QuickSort(mas, leftReplaceElement, endIndex);
    }
    return;

}

void QuickSortRevert(vector<int>& mas, int startIndex, int endIndex){
     vector <int> bufferMass;
     for(int i = startIndex; i<= endIndex; ++i){
         bufferMass.push_back(mas[i]);
     }
    QuickSort(bufferMass, 0, bufferMass.size()-1);
     int i;
     int j;
    for(i = startIndex, j = endIndex; i<= endIndex; ++i, --j){
        mas[j]=bufferMass[i];
    }
}

void EvenSort(vector<int>& mas){
    vector<int> evenNumbers;
    vector<int> unevenNumbers;
    for(auto digit : mas){
        if(digit%2==0){
            evenNumbers.push_back(digit);
        }else{
            unevenNumbers.push_back(digit);
        }
    }
    QuickSort(evenNumbers, 0, evenNumbers.size()-1);
    QuickSortRevert(unevenNumbers, 0, unevenNumbers.size()-1);
    vector<int> bufferMass;
    for(auto digit : evenNumbers){
        bufferMass.push_back(digit);
    }
    for(auto digit:unevenNumbers){
        bufferMass.push_back(digit);
    }
    for(int i = 0; i<=mas.size()-1; ++i){
        mas[i]=bufferMass[i];
    }

}

int main() {

    vector <int> v = {2,5,-8,1,-4,6,3,-5,-9,13,0,4,9};
    vector <int> m = {2,5,-8,1,-4,6,3,-5,-9,13,0,4,9};
    vector <int> x = {2,5,-8,1,-4,6,3,-5,-9,13,0,4,9};
    vector <int> n = {2,5,-8,1,-4,6,3,-5,-9,13,0,4,9};


    printMass(v);
    BubbleSort(v);
    cout << "Bubble sort:\n";
    printMass(v);
    QuickSort(n, 0, n.size()-1);
    cout << "Quick  sort:\n";
    printMass(n);
    QuickSortRevert(m, 0, m.size()-1);
    cout << "Quick revert sort:\n";
    printMass(m);
    EvenSort(x);
    cout << "Even sort:\n";
    printMass(x);

    return 0;
}


