# include <iostream>
# include <string>
# include <windows.h>

using namespace std;

int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int a = 1245;
    cout << "Системы счисления:\n";
    cout.setf(ios_base::showbase|ios_base::uppercase);
    cout.setf(ios_base::hex, ios_base::basefield);
    cout << a << " ";
    cout.setf(ios_base::showbase|ios_base::oct, ios_base::basefield);
    cout << a << " ";
    cout.setf(ios_base::showbase|ios_base::dec, ios_base::basefield);
    cout << a << "\n";
    a = 12;
    cout.setf(ios_base::showpos);
    cout << "Температура воздуха " << a << " градусов\n";
    cout << "Вывод вещественных чисел:\n";
    double b = 0.00000015;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.precision(7);
    cout << b << endl;
    cout.unsetf(ios_base::showpos);
    cout.setf(ios_base::scientific, ios_base::floatfield);
    cout << b << endl;
    a = -123;
    cout << "Заполнение и выравнивание:\n";
    cout.width(8);
    cout.fill('*');
    cout.setf(ios_base::internal, ios_base::adjustfield);
    cout << a << endl;
    cout.width(8);
    cout.fill('*');
    cout.setf(ios_base::left, ios_base::adjustfield);
    cout << a << endl;
    cout.width(8);
    cout.fill('*');
    cout.setf(ios_base::right, ios_base::adjustfield);
    cout << a << endl;
    cout << "Вывод true словами:\n";
    cout.setf(ios_base::boolalpha);
    cout << (a < 12) << " " << (a > 100) << endl;
    return 0;
}