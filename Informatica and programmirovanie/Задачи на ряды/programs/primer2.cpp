#include <iostream>
#include <windows.h>
using namespace std;
int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int a1 = 1, a2 = 1, a, n;
    cout << "Введите номер числа Фибоначчи\n";
    cout << "n="; cin >> n;
    if (n > 2){
        for (int i = 3; i <= n; i++){
            a = a1 + a2;
            a1 = a2;
            a2 = a;
        }
        cout << "a" << n << "=" << a << endl;
    }
    else cout << "a" << n << "=1\n";
    return 0;
}