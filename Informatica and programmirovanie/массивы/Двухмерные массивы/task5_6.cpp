#include <iostream>
using namespace std;
int **create (int n, int m){
    int **a = new int *[n];
    for (int i = 0; i < n; i++)
        a[i] = new int [m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            cout << "a[" << i << "][";
            cout << j << "] = ";
            cin >> a[i][j];
    }
    return a;
}

void print(int **a, int n, int m){
    for (int i = 0; i < n; i++, cout << endl)
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
    cout << endl;
}

void change (int **a, int n, int m){
    int min = a[0][0], max = a[0][0];
    int n_min = 0, n_max = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            if (a[i][j] < min){
                min = a[i][j];
                n_min = i;
            }
            if (a[i][j] > max){
                max = a[i][j]; 
                n_max = i;
            }
        }
        for (int j = 0; j < m; j++)
            swap(a[n_min][j], a[n_max][j]);
}

int main(){
    int n, m;
    cout << "n = "; cin >> n;
    cout << "m = "; cin >> m;
    int **a = create (n, m);
    print(a, n, m);
    change(a, n, m);
    print(a, n, m);
    return 0;
}