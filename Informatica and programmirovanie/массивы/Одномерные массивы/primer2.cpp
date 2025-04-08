# include <iostream>
using namespace std;
int main(){
    int a = 5;
    int *p = new int;
    // int *p = &a;
    cout << "address: " << p << " value: " << *p << endl;
    delete p;
    return 0;
}