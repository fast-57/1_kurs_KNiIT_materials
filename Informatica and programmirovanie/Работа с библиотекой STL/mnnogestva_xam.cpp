# include <iostream>
# include <set>
using namespace std;
bool f1(int x) {return x>=10 && x<=99;}
bool f2(int x) {return x>=100 && x<=999;}
int main(){
    set<int>b, a, c, d;
    int n;
    cin >> n;
    for(int i{0}; i < n; i++)
    {
        int x; cin >> x;
        a.insert(x);    
    }
    for(auto it = a.begin(); it != a.end(); it++)
        cout << *it << " ";
    cout << "\n";
    for(auto it = a.begin(); it != a.end(); it++){ // auto чтобы не писать iterator и т.д.
        int x = *it;
        if(f1(x)) while(x) {b.insert(x%10); x /= 10; }
        if(f2(x)) while(x) {c.insert(x%10); x /= 10; }
    }
    for(auto it = b.begin(); it != b.end(); it++)
        cout << *it << " ";
    cout << "\n";
    for(auto it = c.begin(); it != c.end(); it++)
        cout << *it << " ";
    cout << "\n";
    set_intersection(b.begin(), b.end(), c.begin(), c.end(), inserter(d, d.begin()));
    cout << "\n";
    for(auto it = d.begin(); it != d.end(); it++)
        cout << *it << " ";
    cout << "\n";
}
    


