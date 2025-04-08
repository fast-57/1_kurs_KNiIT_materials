# include <iostream>
# include <vector>
# include <algorithm>
# include <numeric>
# include <windows.h>
using namespace std;

bool odd(int x){
    return x % 2 == 0;
}

int X;
bool kratn(int x){
    return x % X != 0;
}

int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int n;
    cout << "n = "; cin >> n;
    vector<int>vec;

    int x;
    for(int i = 0; i < n; i++){
        cout << "a[" << i << "] = ";
        cin >> x;
        vec.push_back(x);
    }

    for(vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
        cout << *iter << " ";
    cout << endl;

    cout << " Удаление чётных элементов:\n";
    vector<int>::iterator it = remove_if(vec.begin(), vec.end(), odd);
    vec.erase(it, vec.end());

    for(vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
        cout << *iter << " ";
    cout << endl;

    cout << "Замена максимальных\n";
    int Y;
    cout << "Y = "; cin >> Y;
    int Max = *max_element(vec.begin(), vec.end());
    replace(vec.begin(), vec.end(), Max, Y);

    for(vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
        cout << *iter << " ";
    cout << endl;

    cout << "Сумма элементов:\n";
    cout << "X = "; cin >> X;
    vector<int> temp(vec);
    replace_if(temp.begin(), temp.end(), kratn, 0);
    cout << "sum = " << accumulate(temp.begin(), temp.end(), 0) << endl;

    cout << "Сортировка:\n";
    sort(vec.begin(), vec.end());
    for(vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
        cout << *iter << " ";
    cout << endl;

    cout << "Удаление дубликатов:\n";
    vector<int>::iterator iter1 = unique(vec.begin(), vec.end());
    vec.erase(iter1, vec.end());
    for(vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
        cout << *iter <<  " ";
    cout << endl;
    system("pause");
    return 0;
}