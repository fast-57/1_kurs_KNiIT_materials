# include <iostream>
# include <vector>
# include <algorithm>
# include <numeric>
# include <functional>
using namespace std;
int main(){
    vector <int> x;
    int n;
    cout << "n = " << "\n";
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        x.push_back(a);
    }
    for (int i : x)
        cout << i << " ";
    cout << "\n";
}
// 10
// 1 2 3 4 5 6 7 8 9 10
