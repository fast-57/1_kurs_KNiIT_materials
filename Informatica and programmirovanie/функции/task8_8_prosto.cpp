# include <iostream>
# include <windows.h>
using namespace std;

int binom(int k, int n){
    int soch = 1;
    for (int i = k; i > 0; i--){
        soch *= ((n + 1 - k)/k);
        k--;
    }
    return soch;
}
int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int k, n;
    cout << "k = "; cin >> k;
    cout << "n = "; cin >> n;
    if (k >= 1 && n >= k){
        cout << " Число сочетаний = " << binom(k, n);
    }
    else{
        cout << "Ошибка ввода";
    }
    return 0;
}