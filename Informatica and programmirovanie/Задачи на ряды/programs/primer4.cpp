# include <iostream>
# include <math.h>
using namespace std;
int main(){
    int n;
    cout << "n="; cin >> n;
    float x;
    cout << "x="; cin >> x;
    float a = -x*x*x/6, S=a;
    cout << "i\ta\tS\n";
    cout << 1 << "\t| " << a << "\t| " << S << endl;
    for (int i = 2; i <= n; i++){
        a *= -x*x / (2*i * (2*i + 1));
        S += a;
        cout << i << "\t| " << a << "\t| " << S << endl;
    }
    return 0;
}