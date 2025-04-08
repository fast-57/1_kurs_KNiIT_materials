# include <iostream>
using namespace std;
int main(){
    int n;
    cout << "n = "; cin >> n;
    bool flag;
    for (int i = 2; i < n; i++){
        if (n % i == 0){
            flag = true;
            for (int j = 2; j < i; j++){
                if (i % j == 0){
                    flag = false;
                    break;
                }
            }
            if (flag){
                cout << i << "\n";
            }
        }
    }
}