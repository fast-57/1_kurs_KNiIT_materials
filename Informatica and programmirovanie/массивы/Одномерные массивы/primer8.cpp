# include <iostream>
# include <math.h>
# include <windows.h>
using namespace std;
int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int n, z, a[10];
    cout << "n = "; cin >> n;
    for (int i = 0; i < n;i++)
    {
        cout << "a" << i << " = "; cin >> z;
        a[i] = z;
    }
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
        if (!(a[i] % 2) && a[i] > max)
            max = a[i];
    if (max == INT_MIN)
        cout << "чётных элементов нет\n";
    else
        for (int i = 0; i < n; i++)
            if (a[i] == max)
                cout << i << " ";
    cout << endl;
    return 0;
}