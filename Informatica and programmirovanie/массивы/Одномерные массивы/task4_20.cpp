# include <iostream>
# include <math.h>
# include <windows.h>
using namespace std;
int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int n, a[7], z, x, q, k;
    k = 0;
    cout << "n = "; cin >> n;
    int min = INT_MAX;
    for (int i = 0; i < n; i++){
        cout << "a[" << i << "] = "; cin >> z;
        a[i] = z;
    }
    for (int i = 0; i < n; i++){
        if (a[i] < min) min = a[i];
    }
    for (int i = 0; i < n; i++){
        if (a[i] % 2 != 0){
            k += 1;
        }
    }
    if (k == 0){
        cout << "Нечётных элементов нет\n";
    }
    else{
            for (int i = 0; i < n; i++){
        if (a[i] == min && a[i] % 2 != 0) x = i;
    }
    q = a[n-1];
    a[n-1] = a[x];
    a[x] = q;
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    }
    return 0;
}