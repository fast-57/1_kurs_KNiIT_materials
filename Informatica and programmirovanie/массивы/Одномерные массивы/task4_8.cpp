# include <iostream>
# include <math.h>
# include <windows.h>
using namespace std;
int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int n, z, a[8], k;
    k = 0;
    cout << "n = "; cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = "; cin >> z;
        a[i] = z;
    }
    int b, c;
    cout << "b = "; cin >> b;
    cout << "c = "; cin >> c;
    if (b > c){
        swap(b, c);
    }
    else{
        for (int i = 0; i < n; i++){
            if (a[i] % 3 == 0 && (a[i] < b || a[i] > c)){
                cout << i << " ";
                k += 1;
            }
    }
    }
    if (k == 0){
        cout << "Таких элементов нет\n";
    }
    return 0;
}