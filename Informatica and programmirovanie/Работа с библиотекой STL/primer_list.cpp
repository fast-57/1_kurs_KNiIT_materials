# include <iostream>
# include <list>
using namespace std;

int main()
{
    int n = 10;
    list <int> a;
    for(int i = 0; i < n; i+= 2){
        a.push_back(rand()%5);
        a.push_front(rand()%5);
    }

    for(list<int>::iterator it = a.begin(); it != a.end(); it++)
        cout << *it << " ";
    cout << endl;

    int x = 11;
    for(list<int>::iterator it = a.begin(); it != a.end(); it++)
        if (*it % 3 == 0)
            a.insert(it, x);

    for(list<int>::iterator it = a.begin(); it != a.end(); it++)
        cout << *it << " ";
    cout << endl;

    a.sort();

    for(list<int>::iterator it = a.begin(); it != a.end(); it++)
        cout << *it << " ";
    cout << endl;

    a.unique();

    for(list<int>::iterator it = a.begin(); it != a.end(); it++)
        cout << *it << " ";
    cout << endl;

    system("pause");
    return 0;
}