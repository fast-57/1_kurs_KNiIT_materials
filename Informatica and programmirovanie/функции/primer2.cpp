# include <iostream>
using namespace std;
int main(){
    int a = 5;
    int *p = &a;
    cout << "address: " << p << " value: " << *p << endl;
    return 0;
}
