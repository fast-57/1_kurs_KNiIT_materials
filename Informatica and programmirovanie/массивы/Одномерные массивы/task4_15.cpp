# include <iostream>
# include <windows.h>
# include <math.h>
using namespace std;
int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int n, a[8], z, k;
    int max = INT_MIN;
    cout << "n = "; cin >> n;
    for (int i = 0; i < n; i++){
        cout << "a[" << i << "] = "; cin >> z;
        a[i] = z;
    }
    for (int i = 0; i < n; i++){
        if (a[i] % 2 == 0 and a[i] > max){
            max = a[i];
        }
    }
    if (max == INT_MIN)
        cout << "Чётных элементов нет\n";
    else
        for (int i = 0; i < n; i++)
            if (a[i] == max)
                cout << i << " ";
    return 0;
}