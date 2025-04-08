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
    for (int i = 0; i < n; i++, cout << endl)
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
    cout << endl;
}
int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int n, m, min;
    int *b;
    bool flag;
    cout << "Введите количество строк: "; cin >> m;
    cout << "Введите количество столбцов: "; cin >> n;
    int **a = create(n, m);
    print(a, n, m);
    min = INT_MAX;
    for (int i = 0; i < m; i++){
        for (int j= 0; j < n; j++){
            if (a[i][j] < min){
                min = a[i][j];
            }
        }
    }
    for (int i = 0; i < m; ){
        flag = false;
        for (int j = 0; j < n; j++){
            if (a[i][j] == min){
                flag = true;
                break;
            }
        }
        if (flag){
            b = a[i];
            m--;
            for (int j = i; j < n; j++){
                a[j] = a[j + 1];
            }
        }
        else{
            i++;
        }
    }
    print(a, n, m);
}