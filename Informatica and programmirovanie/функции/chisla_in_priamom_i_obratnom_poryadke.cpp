# include <iostream>
using namespace std;
void func_0_n(int n){
    if (n > 0){
        func_0_n(n/10);
        cout << n % 10 << " ";
    }
}

void func_n_0(int n){
    if (n > 0){
        cout << n % 10 << " ";
        func_n_0(n / 10);
    }
}
int main(){
    int n = 12345678;
    func_0_n(n);;
    cout << endl;
    func_n_0(n);
    cout << endl;
    return 0;
}