# include <iostream>
using namespace std;
void f1(int n, char ch){
    for (int i = 0; i < n; i++){
        cout << ch;}
}
void f2(int n, int p, char ch){
    if (p < n*2){
        for (int i = 1, k = 1; i <= p; i+=2, k++){
            f1(n-k, ' '); f1(i, ch); 
            cout << "\n";
        }
        f2(n, p + 2, ch); 
    }
}
int main(){
    int n; cin >> n;
    f2(n, 1, '*');
}