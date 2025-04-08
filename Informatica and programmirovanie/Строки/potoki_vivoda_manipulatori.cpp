# include <iostream>
# include <string>
# include <iomanip>
# include <windows.h>

using namespace std;

int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int a = 1245;
    cout << "Системы счисления:\n";
    cout << showbase << hex << a << " " << oct << a << " " << dec << a << endl;
    a = 12;
    cout << "Температура воздуха " << showpos << a << " градусов\n";
    cout << "Вывод вещественных чисел\n";
    double b = 0.00000015;
    cout << fixed << setprecision(7) << b << endl;
    cout << noshowpos << scientific << b << endl;
    a = -123;
    cout << "Заполнение и выравнивание:\n";
    cout << setw(8) << setfill('*') << left << a << "\n";
    cout << setw(8) << right << a << "\n";
    cout << setw(8) << internal << a << "\n";
    cout << "Вывод true словами:\n";
    cout << boolalpha << (a < 12) << " " << (a > 100) << endl;
    cout << noboolalpha << (a < 12) << " " << (a > 100) << endl;
    return 0;
}