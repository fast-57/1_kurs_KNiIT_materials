# include <iostream>
using namespace std;
void func(int a){
    while (a--){
        static int n = 0;
        int x = 0;
            cout << "n = " << n++ << " x = " << x++ << endl;
    }
}

int main(){
    func(3);
    return 0;
}