# include <iostream>
# include <cmath>
using namespace std;

double F(double i, double N){
    if (abs(i - N) < 0.00001) return sqrt(N);
    else
        return sqrt(i + F(i + 1, N));
}

int main(){
    double N;
    cout << " N = ";
    cin >> N;
    cout << "F = " << F(1, N) << endl;
    return 0;
}