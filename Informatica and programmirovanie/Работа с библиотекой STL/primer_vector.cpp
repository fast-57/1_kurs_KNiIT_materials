# include <iostream>
# include <vector>
using namespace std;

int main()
{
    int n = 10;
    vector<int>a;
    for (int i = 0; i < n; i++)
        a.push_back(i);

    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << endl;

    int x = 11;
    for (int i = 0; i < a.size(); i++)
        if (a[i] % 3 == 0)
            a.insert(a.begin() + i + 1, x);

    for (vector<int>::iterator it = a.begin(); it != a.end(); it++)
        cout << *it << " ";
    cout << endl;

    a.erase(a.begin() + 2, a.begin() + 5);

    for (vector<int>::iterator it = a.begin(); it != a.end(); it++)
        cout << *it << " ";
    cout << endl;

    system("pause");
    return 0;
}