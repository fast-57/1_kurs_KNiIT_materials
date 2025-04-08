# include <iostream>
# include <vector>
# include <algorithm>
# include <numeric>
# include <functional>
using namespace std;
int a, b;
bool f1(int x) {return x >= a && x <= b;}
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
    cin >> a >> b;
    function <bool(int)> operatoin{f1};
    vector <int> :: iterator it = remove_if(x.begin(), x.end(), operatoin);
    x.erase(it, x.end());
    for(vector<int>::iterator it1 = x.begin(); it1 != x.end(); it1++)
        cout << *it1 << " ";
    cout << "\n";
}