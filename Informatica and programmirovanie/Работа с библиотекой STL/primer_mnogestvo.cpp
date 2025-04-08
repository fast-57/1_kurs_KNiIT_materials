# include <iostream>
# include <set>
using namespace std;

int main()
{
    int n = 10;
    set<int>a;
    for(int i = 0; i < n; i++)
        a.insert(rand()%10);

    for(set<int>::iterator it = a.begin(); it != a.end(); it++)
        cout << *it << " ";
    cout << endl;

    cout << *a.lower_bound(3) << " " << *a.upper_bound(3) << " ";
    cout << *a.equal_range(3).first << " - " << *a.equal_range(3).second << endl;

    cout << *a.lower_bound(7) << " " << *a.upper_bound(7) << " ";
    cout << *a.equal_range(7).first << " - " << *a.equal_range(7).second << endl;

    system("pause");
    return 0;
}