#include <iostream>
#include <limits.h>
using namespace std;

int main(){
    setlocale(LC_ALL, "RUS");
    int n, mn=INT_MAX, x;
    cout << "Введите длину массива\n";
    cin >> n;
    cout << "Введите число X\n";
    cin >> x;
    int* mas = new int(2*n);
    cout << "Введите элементы массива\n";
    for (int i=0; i < n; i++){
        cin >> mas[i];
        if (mas[i] < mn)
            mn = mas[i];}

    for (int i = 0; i < n; ) {
        if (mas[i] == mn) {
            n+=1;
            for (int j = n; j > i + 1; j-=1) { // сдвиг элементов вправо 
                mas[j] = mas[j-1];
            }
            mas[i+1] = x; // заполнение освободившейся ячейки
            i+=2; // переход через новый элемент
        }
        else {
            i++;
        }
    }


    for (int i = 0; i < n; i++)
        cout << mas[i] << " ";
    return 0;
}