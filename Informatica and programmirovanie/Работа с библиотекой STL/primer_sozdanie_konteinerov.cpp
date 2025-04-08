# include <iostream>
# include <vector>
# include <set>
# include <list>
using namespace std;

int main()
{
    int n = 10;
    vector<int>a;

    for(int i = 0; i < n; i++)
        a.push_back(rand()%5);

    for(vector<int>::iterator it = a.begin(); it != a.end(); it++)
        cout << *it << " ";
    cout << endl;

    vector<int>b(n, 5);

    for(vector<int>::iterator it = b.begin(); it != b.end(); it++)
        cout << *it << " ";
    cout << endl;

    vector<int>c(a);

    for(vector<int>::iterator it = c.begin(); it != c.end(); it++)
        cout << *it << " ";
    cout << endl;

    set<int>d(a.begin(), a.end());

    for(set<int>::iterator it = d.begin(); it != d.end(); it++)
        cout << *it << " ";
    cout << endl;

    list <int>e(a.begin() + 1, a.begin() + 5);

    for(list<int>::iterator it = e.begin(); it != e.end(); it++)
        cout << *it << " ";
    cout << endl;

    system("pause");
    return 0;
}