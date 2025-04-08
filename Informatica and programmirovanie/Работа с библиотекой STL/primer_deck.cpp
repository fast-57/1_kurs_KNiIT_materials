# include <iostream>
# include <deque>
using namespace std;

int main()
{
    int n = 10;
    deque<int>a;
    for(int i = 0; i < n; i+=2){
        a.push_back(i);
        a.push_front(i + 1);
    }

    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << endl;

    int x = 11;
    for(int i = 0; i < a.size(); i++)
        if (a[i] % 3 == 0)
            a.insert(a.begin() + i + 1, x);

    for(deque<int>::iterator it = a.begin(); it != a.end(); it++)
        cout << *it << " ";
    cout << endl;

    a.erase(a.begin() + 2, a.begin() + 5);

    for(deque<int>::iterator it = a.begin(); it != a.end(); it++)
        cout << *it << " ";
    cout << endl;

    system("pause");
    return 0;
}