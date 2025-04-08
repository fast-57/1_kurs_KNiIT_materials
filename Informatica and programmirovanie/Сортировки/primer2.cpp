# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
int **create(int n){
    int **a = new int *[n];
    for(int i = 0; i < n; i++){
        a[i] = new int[n];
    }
    return a;
}
int main(){
    int n;
    cout << "n = "; cin >> n;
    int **a = create(n);
    for(int k = 1; k < 2*n-2; k++){
        vector<int> b;
        for(int i = 0; i < n; i++){
            if (k - i < n && k - i >= 0){
                b.push_back(a[i][k-i]);
            }
        }
        sort(b.begin(), b.end());
        int L = 0;
        for(int i = 0; i < n; i++){
            if (k - i < n && k - i >= 0){
                a[i][k-i] = b[L];
                L++;
            }
        }
    }
}