# include <iostream>
# include <cmath>
using namespace std;
int main(){
    int n, z, proizv1, proizv2;
    cout << "n = "; cin >> n;
    int *a = new int[n];
    int c = n;
    for (int i = 0; i <= n; i++){
        cout << "z" << i << " = ";
        cin >> z;
        a[i] = z;
    }
    for (int i = 0; i <= n; i++, cout << " "){
        proizv1 = c*a[i];
        c -= 1;
        proizv2 = proizv1*c;
        cout << proizv2;
    }
}
