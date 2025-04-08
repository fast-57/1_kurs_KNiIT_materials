# include <iostream>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include <windows.h>
using namespace std;
int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int n = 4;
    int a[4];
    int b, c;
    cout << "b="; cin >> b;
    cout << "c="; cin >> c;
    for (int i = 0; i < n; i++){
        int z;
        cout << "z" << i << " = ";
        cin >> z;
        a[i] = z;
    }
    if (b > c) swap(b, c);
    int k = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
        if (a[i] % 3 == 0 && (a[i] < b || a[i] > c)){
            k++;
            sum += a[i];
    }
    if (!k) cout << "Таких элементов нет\n";
    else
        cout << "Среднее арифметическое: " << 1.0*sum/k << endl;
        return 0;
}