# include <iostream>
# include <vector>
using namespace std;
int main(){
    int n, x, i = 0;
    cout << "n = "; cin >> n;
    vector<int>a;
    for(int i = 0; i < n; i++){
         x = rand();
        a.push_back(x);
        cout << a[i] << " ";
    }
    cout << "\n";
    while(i < a.size() - 1){
        if (a[i] > a[i + 1]){
            swap(a[i], a[i+1]);
            i = 0;
        }
        else{
            i++;
        }
    }
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}