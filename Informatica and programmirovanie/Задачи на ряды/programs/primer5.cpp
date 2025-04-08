# include <iostream>
# include <math.h>
# include <iomanip>
using namespace std;
int main(){
    int N = 100;
    float x, eps;
    cout << "x="; cin >> x;
    cout << "eps="; cin >> eps;
    float a = x, S = a;
    cout << left << setw(3) << "i\t" << setw(10) << "a\t";
    cout << setw(10) << "S" << endl;
    cout << left << setw(3) << 1 << "\t" << setw(10) << a;
    cout << "\t" << setw(10) << S << endl;
    for (int i = 2; abs(a) > eps && i <= N; i++){
        S += a;
        a*=x/i;
        cout << left << setw(3) << i << "\t" << setw(10) << a;
        cout << "\t" << setw(10) << S << endl;
    }
    return 0;
}