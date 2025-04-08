# include <iostream>
# include <cmath>
# include <windows.h>
using namespace std;

int binom(int n, int k){
    if (k == 0)
        return 1;
    else
        return ((n + 1 - k) / k)*binom(n, k - 1);
}
int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int n, k;
    cout << "n = "; cin >> n;
    cout << "k = "; cin >> k;
    if (k >= 1 && n >= k){
        cout << "Число сочетаний k по n = " << binom(n, k);
    }
    else{
        cout << "Ошибка ввода";
    }
}