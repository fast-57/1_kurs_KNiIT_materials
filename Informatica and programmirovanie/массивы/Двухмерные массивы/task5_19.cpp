# include <iostream>
using namespace std;
int **create (int n){
    int **a = new int *[n];
    for (int i = 0; i < n; i++)
        a[i] = new int [n];
    return a;
}
void print(int **a, int n){
    int z;
    int x;
    int c;
    x = 0;
    c = 9;
    int k = 0;
    a[0][0] = 0;
    for (int j = 0; j < n; j++, cout << endl){
        z = k;
        x = c;
        for (int i = 0; i < n; i++){
            if (i % 2 == 0){
                a[i][j] = z;
                z += 10;
                cout << a[i][j] << " ";
            }
            else{
                a[i][j] = x;
                x += 10;
                cout << a[i][j] << " ";
            }
            }
        k += 1;
        c -= 1;
        }
    }


int main()
{
    int n;
    cout << "n = "; cin >> n;
    int **a = create(n);
    print(a, n);
}