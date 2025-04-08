# include <iostream>
# include <cmath>
using namespace std;
int main(){
    int A;
    cout << "A = ";
    cin >> A;
    bool fl;
    do{
        fl = true;
        for(int i = 2; i <= sqrt((float)A) + 0.01; i++)
            if (A % i == 0){
                fl = false;
                break;
            }
            A++;
    }
    while (!fl);
    cout << --A << endl;
    return 0;
}