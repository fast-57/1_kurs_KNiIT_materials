# include <iostream>
# include <cmath>
using namespace std;
int main(){
    setlocale(LC_ALL, "rus");
    int A, Y, X, a, b, c;
    cout << "Введите трёхзначное число: ";
    cin >> A;
    cout << "Введите однозначное число: ";
    cin >> Y;
    cout << "Введите число от 0 до 4 включительно: ";
    cin >> X;
    a = A / 100;
    b = (A / 10) % 10;
    c = A % 10;
    if (A >= 100 and A <= 999 and Y >= 0 and Y <= 9 and X >= 0 and Y <= 4){
        if (a % X == 0 and b % X == 0 and c % X == 0){
            a = (a * Y) % 10;
            b = (b * Y) % 10;
            c = (c * Y) % 10;
            int z = a * 100 + b * 10 + c;
            cout << z;}
        else if (a % X == 0 and b % X == 0){
            a = (a * 3) % 10;
            b = (b * 3) % 10;
            c = (c * 3) % 10;
            int z = a*100 + b*10 + c;
            cout << z;}
        else if (a % X == 0 and c % X == 0){
            a = (a + Y) % 10;
            b = (b + Y) % 10;
            c = (c + Y) % 10;
            int z = a*100 + b*10 + c;
            cout << z;}
        else if (b % X == 0 and c % X == 0){
            a = abs(a - Y);
            b = abs(b - Y);
            c = abs(c - Y);
            int z = a*100 + b*10 + c;
            cout << z;}
        else{
            a = (a * 2) % 10;
            b = (b * 2) % 10;
            c = (c * 2) % 10;
            int z = a*100 + b*10 + c;
            cout << z;}
    }
    else 
        cout << "некорректный ввод";
    system("pause");
    return 0;

}