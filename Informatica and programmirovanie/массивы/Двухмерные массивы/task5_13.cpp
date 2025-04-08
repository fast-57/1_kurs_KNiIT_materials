# include <iostream>
using namespace std;
int **create (int n){
    int **a = new int *[n];
    for (int i = 0; i < n; i++)
        a[i] = new int [n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            cout << "a[" << i << "][";
            cout << j << "] = ";
            cin >> a[i][j];
        }
    return a;
}

void print( int **a, int n){
    for (int i = 0; i < n; i++, cout << endl)
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
    cout << endl;
}
void change(int **a, int n){
    int min = a[0][0], max = a[0][0], i_min = 0, j_min = 0, i_max = 0, j_max = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            if ((a[i][j] < min) && (a[i][j] % 2 == 0) && (i >= j)){
                min = a[i][j];
                i_min = i;
                j_min = j;
            }
            if ((a[i][j] > max) && (a[i][j] % 2 != 0) && (i < j)){
                max = a[i][j];
                i_max = i;
                j_max = j;
            }
        }
    swap(a[i_min][j_min], a[i_max][j_max]);
}
int main(){
    int n, m;
    cout << "n = "; cin >> n;
    int **a = create(n);
    print(a, n);
    change(a, n);
    print(a, n);
    return 0;
}