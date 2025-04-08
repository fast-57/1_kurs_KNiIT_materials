# include <iostream>
# include <windows.h>
using namespace std;
int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int n, m, k;
    cout << "n = "; cin >> n;
    cout << "Строка: "; cin >> m;
    cout << "Столбец: "; cin >> k;
    if (k > m){
        swap(k, m);
    }
    int **a = new int *[n + 1];
    for (int i = 0; i <= n; i++)
        a[i] = new int [i + 1];
    a[0][0] = 1;
    a[1][0] = a[1][1] = 1;
    for (int i = 2; i <= n; i++){
        a[i][0] = 1;
        for (int j = 1; j < i; j++)
            a[i][j] = a[i-1][j-1] + a[i-1][j];
        a[i][i] = 1;
    }
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= i; j++){
            if (i == m && j == k && n >= m && n >= k){
                cout << a[i][j];
            }
        }
    return 0;

}
