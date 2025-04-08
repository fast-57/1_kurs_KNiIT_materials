# include <iostream>
using namespace std;

int prostoe(int n, int i){
    while (n % i == 0){
        n = n / i;
        cout << i << " ";
    }
    return prostoe(n, i + 1);
}

int main(){
    int n, z;
    cout << "n = "; cin >> n;
    cout << "prostie = " << prostoe(n, 2);
    return 0;
}