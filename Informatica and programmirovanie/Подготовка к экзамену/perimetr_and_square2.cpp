# include <iostream>
# include <cmath>
# include <windows.h>
using namespace std;
void point(float&x, float &y)
{
    cout << "x=";
    cin >> x;
    cout << "y=";
    cin >> y;
}

float dlina(float xa, float ya, float xb, float yb)
{
    return sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));
}

float perimetr(float a, float b, float c)
{
    return a + b + c;
}

bool treug(float a, float b, float c)
{
    if ((a + b > c) && (a + c > b) && (c + b > a)) return 1;
    else return 0;
}

float sqr(float a, float b, float c)
{
    float p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
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
    a - dlina(x1, y1, x2, y2);
    cout << "a=" << a << endl;
    b = dlina(x2, y2, x3, y3);
    cout << "b=" << b << endl;
    c = dlina(x1, y1, x3, y3);
    cout << "c=" << c << endl;
    float p, s;
    if (treug(a, b, c))
    {
        p = perimetr(a, b, c);
        s = sqr(a, b, c);
        cout << "p=" << p << endl;
        cout << "s=" << s << endl;
    }
    else cout << "error";
    return 0;
    
}
