# include <iostream>
using namespace std;

int NOD(int a, int b){
    if (a == b) return a;
    else if (a > b){
        cout << a << "\t" << b << endl;
        return NOD(a - b, b);
    }
    else{
        cout << a << "\t" << b << endl;
        return NOD(a, b - a);
    }
}

int main(){
    int a, b;
    cout << "a=";
    cin >> a;
    cout << "b=";
    cin >> b;
    cout << "a\tb\n";
    cout <<"NOD=" << NOD(a, b) << endl;
    return 0;
}