# include <iostream>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
using namespace std;
int main(){
    int a[10], n;
    cout << "n = "; cin >> n;
    srand ((unsigned int)time(NULL));
    for (int i = 0; i < n; i++){
        a[i] = rand() % 15;
        cout <<  "a[" << i << "]=" << a[i] << endl;
    }
    return 0;
}