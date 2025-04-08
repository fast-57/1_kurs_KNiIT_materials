# include <iostream>
# include <cmath>
using namespace std;

void print(int n, char a){
    for (int i = 0; i < n; i++)
        cout << a;
}

void F(int p, int n, char a){
    if (n > 0){
        print(p, ' ');
        print(n, a);
        cout << endl;
        F(p + 1, n - 2, a + 1);
        print(p, ' ');
        print(n, a);
        cout << endl;
    }
}

int main(){
    int N;
    do{
        cout << " Input N < 18 \n";
        cin >> N;
    }
    while (N > 18);
    if (N % 2 == 0) N--;
    F(1, N, '1');
    return 0;
}