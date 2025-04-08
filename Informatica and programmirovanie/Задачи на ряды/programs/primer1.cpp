# include <windows.h>
# include <iostream>
using namespace std;
int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int a, d, n;
    cout << "Введите первый член прогрессии\n";
    cout << "a1="; cin >> a;
    cout << "Введите разность прогрессии\n";
    cout << "d="; cin >> d;
    cout << "Введите количество членов прогрессии\n";
    cout << "n="; cin >> n;
    cout << "a" << 1 << "=" << a << endl;
    for (int i = 2; i <= n; i++){
        a += d;
        cout << "a" << i << "=" << a << endl;
    }
    return 0;
}