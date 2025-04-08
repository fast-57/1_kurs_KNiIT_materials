# include <iostream>
# include <windows.h>
using namespace std;
int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    float y1 = 0.9, y2 = 1.1, n, y;
    cout << "Введите количество первых членов последовательности: \n";
    cout << "n = "; cin >> n;
    cout << "y1 = " << y1 << endl;
    cout << "y2 = " << y2 << endl;
    if (n > 2){
        for ( int i = 3; i <= n; i++){
            y = y2/i + y1/(i*i);
            y1 = y2;
            y2 = y;
            cout << "y" << i << " = " << y << endl;
        }
    }
    else if (n == 1){
        cout << "y" << n << " = " << y1 << endl;
    }
    else{
        cout << "y" << n << " = " << y2 << endl;
    }
    return 0;


}