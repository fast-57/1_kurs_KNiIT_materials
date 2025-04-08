# include <iostream>
# include <deque>
# include <algorithm>
# include <windows.h>
using namespace std;
int X;

bool kratn(int x){
    return x % X == 0;
}
int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int n, m;
    cout << "n = "; cin >> n;
    cout << "m = "; cin >> m;
    cout << "X = "; cin >> X;
    deque<int>dec1;
    deque<int>dec2;
    for(int i = 0; i < n; i+=2){
        dec1.push_back(i);
        dec1.push_front(i + 1);
    }
    for(int i = 0; i < m; i++){
        dec2.push_back(i);
        dec2.push_front(i);
    }
    for(deque<int>::iterator iter = dec1.begin(); iter != dec1.end(); iter++)
        cout << *iter << " ";
    cout << endl;
    
    for(deque<int>::iterator iter = dec2.begin(); iter != dec2.end(); iter++){
        cout << *iter << " ";
    }
    cout << endl;

    cout << "Удаление элементов дека a, кратных X:\n";
    deque<int>::iterator it = remove_if(dec1.begin(), dec1.end(), kratn);
    dec1.erase(it, dec1.end());

    for(deque<int>::iterator iter = dec1.begin(); iter != dec1.end(); iter++)
        cout << *iter << " ";
    cout << endl;

    cout << "Замена элементов дека b, попадающих в интервал [a, b] числом Y:\n";
    int Y, a, b;
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    cout << "Y = "; cin >> Y;
    if (a < 0 || b >= dec2.size() || a > b){
        cout << "Некорректный интервал [a, b]\n";
    }
    else{
        for(int i = a; i <= b; i++){
            dec2[i] = Y;
        }
        for(deque<int>::iterator iter = dec2.begin(); iter != dec2.end(); iter++){
            cout << *iter << " ";
        }
        cout << endl;
    }
    cout << "Сортировка:\n";
    sort(dec1.begin(), dec1.end());
    sort(dec2.begin(), dec2.end());
    for(deque<int>::iterator iter = dec1.begin(); iter != dec1.end(); iter++)
        cout << *iter << " ";
    cout << endl;
    
    for(deque<int>::iterator iter = dec2.begin(); iter != dec2.end(); iter++){
        cout << *iter << " ";
    }
    cout << endl;

    deque<int>result(dec1.size() + dec2.size());
    merge(dec1.begin(), dec1.end(), dec2.begin(), dec2.end(), result.begin());
    cout << "Объединённая отсортированная последовательность:\n";
    for(deque<int>::iterator iter = result.begin(); iter != result.end(); iter++)
        cout << *iter << " ";
    cout << endl;

    return 0;
}
