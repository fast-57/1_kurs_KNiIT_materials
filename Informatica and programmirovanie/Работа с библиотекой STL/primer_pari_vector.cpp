# include <iostream>
using namespace std;

int main()
{
    pair<int, char> a;

    a.first = 1;
    a.second = 'C';

    cout << a.first << " " << a.second << endl;

    pair<int, char> b(2, 'B');

    cout << b.first << " " << b.second << endl;

    pair<int, char> c;
    c = make_pair(1, 'A');

    cout << c.first << " " << c.second << endl;

    if (a < c) cout << "a < c\n";
    else cout << "c < a\n";

    system("pause");
    return 0;
}