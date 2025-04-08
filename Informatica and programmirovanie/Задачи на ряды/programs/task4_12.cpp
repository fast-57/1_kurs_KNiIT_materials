# include <iostream>
# include <math.h>
# include <windows.h>
using namespace std;
int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int n = 200;
    float eps = 0.0001, x, an, S;
    cout << "Введите x: \n";
    cin >> x;
    S = an = x;
    for (int i = 3; i <= n && abs(an) > eps; i+=2){
        an *= -(x * x) / ((i - 1) * i);
        S += an;
        if (i == n){
            cout << "Ряд расходится\n";
            return 0;
        }
    }
    cout << "Сумма равна: " << S;
    return 0;
}
