# include <iostream>
# include <cmath>
# include <windows.h>
using namespace std;

void point(float &x, float &y)
{
    cout << "x=";
    cin >> x;
    cout << "y=";
    cin >> y;
}

float dlina()
{
    return 1;
}

float perimetr()
{
    return 2;
}

float treug()
{
    return 3;
}

float sqr()
{
    return 4;
}
int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    float x1, x2, x3, y1, y2, y3;
    cout << "Введите координаты 1 точки\n";
    point(x1, y1);
    cout << "Введите координаты 2 точки\n";
    point(x2, y2);
    cout << "Введите координаты 3 точки\n";
    point(x3, y3);
    float a, b, c;
    a - dlina();
    cout << "a=" << a << endl;
    b = dlina();
    cout << "b=" << b << endl;
    c = dlina();
    cout << "c=" << c << endl;
    float p, s;
    if (treug())
    {
        p = perimetr();
        s = sqr();
        cout << "p=" << p << endl;
        cout << "s=" << s << endl;
    }
    else cout << "error";
    return 0;
    
}
