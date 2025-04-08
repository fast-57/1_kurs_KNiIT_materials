# include <iostream>
# include <windows.h>
using namespace std;
int **create (int n, int m){
    int **a = new int *[m];
    for (int i = 0; i < m; i++)
        a[i] = new int [n];
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cout << "a[" << i << "][";
            cout << j << "] = ";
            cin >> a[i][j];
        }
    }
    return a;
}
void print( int **a, int n, int m){
    for (int i = 0; i < m; i++, cout << endl)
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
    cout << endl;
}

int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int n, m, Y, X;
    int *b = new int(n);
    bool flag;
    cout << "Введите число: "; cin >> Y;
    cout << "Введите количество строк: "; cin >> m;
    cout << "Введите количество столбцов: "; cin >> n;
    for (int i = 0; i < n; i++){
        cout << "X [" << i << "] = ";
        cin >> X;
        b[i] = X;
    }
    int **a = create(n, m);
    print(a, n, m);
    for (int i = 0; i < m; i++){
        int z = 0;
        for (int j = 0; j < n; j++){
            z += a[j][i];
        }
        if (z % Y == 0){
            m++;
            for (int j = 0; j < n; j++){
                for (int k = m - 1; k > i; k--){
                    a[j][k] = a[j][k - 1];
                }
            }
            for (int j = 0; j < n; j++){
                a[j][i] = b[j];
            }
            i++;
        }
    }
    print(a, m, n);
}