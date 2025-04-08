# include <iostream>
# include <cmath>
using namespace std;

double F(double i, double N){
        if (abs(i - N) < 0.00001) 
            for (int j = 1; j < N; j++) 
                return sqrt(N+=j);
        else
                return sqrt(1 + (i + 1)*F(i + 1, N));
    }


int main(){
    double N, i;
    cout << " N = ";
    cin >> N;
    cout << "F = " << F(1, N) << endl;
    return 0;
}