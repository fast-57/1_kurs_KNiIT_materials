# include <iostream>
# include <windows.h>
using namespace std;
int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int n, z, a[10];
    cout << "n = "; cin >> n;
    for (int i = 0; i < n; i++){
        cout << "a" << i << " = "; cin >> z;
        a[i] = z;
    }
    int min = a[0];
    for (int i = 1; i < n; i++){
        if (a[i] < min) min = a[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] == min) a[i] = 0;
    }
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}