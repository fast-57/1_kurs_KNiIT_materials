#include <iostream>
#include <windows.h>
using namespace std;

int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int n = 100;
    float eps = 0.0001, x, an = 1, S = 1; // eps для контроля сходящегося ряда
    cout << "Введите x: \n";
    cin >> x;
    for (int i = 1; i <= n && abs(an) > eps; i++)
    {
        an *= -x; // каждый следующий член последовательности находится умножением предыдущего на -x
        S += an;
        if (n == i)
        {
            cout << "Ряд Расходящийся\n";
            return 0;
        }
    }
    cout << "Сумма равна " << S;
    return 0;
}