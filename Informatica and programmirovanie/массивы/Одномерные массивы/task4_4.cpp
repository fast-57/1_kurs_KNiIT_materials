# include <iostream>
# include <windows.h>
using namespace std;
int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int n, a[8], z;
    cout << "n = "; cin >> n;
    for (int i = 0; i < n; i++){
        cout << "z" << i << " = ";
        cin >> z;
        a[i] = z;
    }
    int b, c, k = 0, sum = 0;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;
    for (int i = 0; i < n; i++)
    {
        if (b > c)
        {
            swap(b, c);
        }
        if (a[i] % 2 != 0 && (a[i] < b || a[i] > c))
        {
            k += 1;
            sum += a[i];
        }

    }
    if (k == 0) cout << "таких элементов нет";
    else
        cout << "Среднее арифметическое = " << 1.0*sum / k;
    return 0;
}