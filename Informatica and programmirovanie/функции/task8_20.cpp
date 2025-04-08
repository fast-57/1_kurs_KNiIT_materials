#include<iostream>
using namespace std;

void print(int n, char c){
    for (int i = 0; i < n; i++) 
        cout << c;
}

void f(int i, int n){
    if (n <= 0 || i > n){ 
        return ;
    }
    for (int j = 2*i + 1; j >= 1; j -=2) {
            print(n - j/2, ' ');
            print(j, '*');
            cout << '\n';
        }
    f(i + 1, n);
}
int main(){
    int n;
    do {
        cout << "n = ";
        cin >> n;
    }
    while (n < 1);
    f(1, n);
}