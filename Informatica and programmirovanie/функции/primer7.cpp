# include <iostream>
using namespace std;

int func(int *a, int *b){
    cout << "function: " << endl;
    cout <<"address: " << a << " " << b << endl;
    *a = *a + 1;
    *b = *b + 2;
    cout << "value: " << *a << " " << *b << endl;
    return *a + *b;
}

int main(){
    int a = 5;
    int b = 3;
    cout << "before: " << endl;
    cout << "value: " << a << " " << b << endl;
    cout << "address: " << &a << " " << &b << endl;
    int c = func(&a, &b);
    cout << "after: " << endl;
    cout << "value: " << a << " " << b << endl;
    cout << "address: " << &a << " " << &b << endl;
    return 0;
}