# include <iostream>
# include <cmath>
using namespace std;
int main(){
    setlocale(LC_ALL, "rus");
    float x, F;
    cout << "x = ";
    cin >> x;
    if (x + 5 < 0){
        cout << "Корень из отрицательного числа\n";}
    else if (sqrt(x * x + 2 * x + 1) == 0){
        cout << "Деление на ноль\n";}
    else if ((8 - 2 * x) <= 0){
        cout << "Логарифм из неположительного числа\n";}
    else {
        F = (sqrt(x + 5) + log(8 - 2 * x)) / (sqrt(x * x + 2 * x + 1));
        cout << "F = " << F << endl;}
    system("pause");
    return 0;
}