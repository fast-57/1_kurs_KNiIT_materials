# include <iostream>
using namespace std;
void f1(int n, char ch){
    for (int i = 0; i < n; i++){
        cout << ch;}
}
void f2(int n, int k, int p, char ch){
    if (n >= 0){
        f1(p, ch); f1(n, ' '); f1(k, ch);
        f1(n, ' '); f1(p, ch); cout << "\n";
        f2(n-2, p+1, k + 2, ch);
        f1(p, ch); f1(n, ' '); f1(p, ch); cout << "\n";
        f1(n, ' '); f1(p, ch); cout << "\n";
    }
}
int main(){
    int n; cin >> n;
    f2(n, 1, 1, '*');
}