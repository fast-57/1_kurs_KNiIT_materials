# include <iostream>
using namespace std;
int a = 5;
void func(int x, int y){
    x++;
    y--;
    cout << "vnutri\n";
    cout << "x = " << x << "y = " << y << " a = " << a << endl;
}

int main(){
    int a = 1;
    cout << "local a = " << a << " global a = " << ::a << endl;
    int x = 5, y = 5;
    func(x, y);
    cout << "vne\n";
    cout << "x = " << x << " y = " << y << endl;
    return 0;
}