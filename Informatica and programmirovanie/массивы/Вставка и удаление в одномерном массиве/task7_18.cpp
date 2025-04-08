# include <iostream>
# include <windows.h>
# include <limits.h>
using namespace std;

int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int n, x;
    cout << "Введите длину массива\n";
    cin >> n;
    cout << "Введите число X\n";
    cin >> x;
    int* mas = new int(2*n);
    for (int i=0; i < n; i++){
        cout << "Введите элемент массива: ";cin >> mas[i];
    }
    for (int i = 0; i < n; ) {
        if (mas[i] % 2 == 0) {
            n+=1;
            for (int j = n; j > i + 1; j-=1) { 
                mas[j] = mas[j-1];
            }
            mas[i+1] = x; 
            i+=2; 
        }
        else {
            i++;
        }
    }



    for (int i = 0; i < n; i++)
        cout << mas[i] << " ";
    return 0;
}