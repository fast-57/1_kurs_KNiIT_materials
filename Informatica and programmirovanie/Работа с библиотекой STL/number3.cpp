# include <iostream>
# include <list>
# include <cmath>
# include <numeric>
# include <functional>
# include <windows.h>
using namespace std;
int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int n;
    cout << "n = "; cin >> n;
    list<int>a;
    for(int i = 1; i < n; i+= 2){
        a.push_back(i);
        a.push_front(i);
    }
    for(list<int>::iterator it = a.begin(); it != a.end(); it++)
        cout << *it << " ";
    cout << endl;

    float sredn_arifm = accumulate(a.begin(), a.end(), 0) / a.size();
    float proizv = accumulate(a.begin(), a.end(), 1.0, multiplies<float>());
    float sredn_geom = exp(log(proizv) / a.size());
    cout << "Среднее арифметическое = " << sredn_arifm << endl;
    cout << "Среднее геометрическое = " << sredn_geom << endl;
    return 0;
}