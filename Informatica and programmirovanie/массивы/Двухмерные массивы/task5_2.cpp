# include <iostream>
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
void print (int **a, int n, int m){
    for (int i = 0; i < n; i++, cout << endl)
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
    cout << endl;
}
void change (int **a, int n, int m){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n-1; j+=2){
            swap(a[i][j], a[i][j+1]);
            }
    }
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