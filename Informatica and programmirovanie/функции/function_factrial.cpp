# include <iostream>
using namespace std;

int f(int n){
    if (n < 0) return -1;
    if (n == 0 || n == 1){
        cout << "n = " << n << " address " << &n << endl;
        return 1;
    }
    else{
        cout << "n = " << n << " address " << &n << endl;
        return n*f(n-1);
    }
}
int main(){
    cout << f(5) << endl;
    return 0;
}