# include <iostream>
# include <vector>
# include <windows.h>
# include <algorithm>
using namespace std;
int X;
bool kratn(int x){
    return x % X == 0;
}
int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int n;
    cout << "n = "; cin >> n;
    vector<int>vec;
    int x;
    for(int i = 0; i < n; i++){
        cout << "a[" << i << "] = ";
        cin >> x;
        vec.push_back(x);
    }
    
    for(vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
        cout << *iter << " ";
    cout << endl;
    int Max = *max_element(vec.begin(), vec.end());
    cout << "X = "; cin >> X;
    replace_if(vec.begin(), vec.end(), kratn, Max);

    for(vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
        cout << *iter << " ";
    cout << endl;
}