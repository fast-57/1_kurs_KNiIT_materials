# include <iostream>
# include <math.h>
using namespace std;
int main(){
    float S = 0, n;
    cout << "n="; cin >> n;
    for (float i = 1; i <= n; i++){
        S += 1 / sqrt(abs(sin(i)));
    }
    cout << "S = " << S << endl;
    return 0;
}