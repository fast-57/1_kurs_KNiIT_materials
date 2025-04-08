# include <iostream>
# include <windows.h>
# include <limits.h>
using namespace std;
int **create (int n, int m){
    int **a = new int *[m];
    for (int i = 0; i < n; i++)
        a[i] = new int [n * n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            cout << "a[" << i << "][";
            cout << j << "] = ";
            cin >> a[i][j];
        }
    return a;
}
void print(int **a, int n, int m){
    for (int i = 0; i < m; i++, cout << endl)
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
    cout << endl; 
}
void vstavka(int **a, int n, int m, bool flag){
    for (int i = m; i > 0; ){
        flag = true;
        for (int j = 0; j < n; j++){
            if (a[i][j] % 2 == 0){
                flag = false;
                break;
            }
            else{
                i--;
            }
        }
        if (flag){
            m += 1;
            for (int j = 0; j < n; j++){
                a[i+1][j] = a[i][j];
            }
            for (int j = 0; j < n; j++){
                a[i][j] = a[i-1][j];
            }
            i += 2;

        }
    }
}
int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int n, m;
    bool flag;
    cout << "Введите длину строки\n";
    cin >> n;
    cout << "Введите длину столбца\n";
    cin >> m;
    int **a = create(n, m);
    print(a, n, m);
    vstavka(a, n, m, flag);
    print(a, n, m);
    return 0;
}