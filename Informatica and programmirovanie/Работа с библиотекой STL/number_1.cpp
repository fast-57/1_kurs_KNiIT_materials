# include <iostream>
# include <set>
# include <string>
# include <algorithm>
# include <vector>
using namespace std;

int main(){
    int n = 10;
    set<int>a;
    for(int i = 0; i < n; i++){
        int el;
        cout << "Введите число: " << "\n";
        cin >> el;
        a.insert(el);
    }
    set<char> dvyxznach;
    set<char> trexznach;
    for (set<int>::iterator it = a.begin(); it != a.end(); it++){
        if(*it >= 10 && *it <= 99){
            string numstr = to_string(*it);
            for(int i = 0; i < numstr.length(); i++){
                dvyxznach.insert(numstr[i]);
            }
        }
        else if(*it > 99 && *it < 1000){
            string numstr = to_string(*it);
            for(int i = 0; i < numstr.length(); i++){
                trexznach.insert(numstr[i]);
            }
        }
    }
    set<char> itog_numbers;
    set_difference(dvyxznach.begin(), dvyxznach.end(), trexznach.begin(), trexznach.end(), inserter(itog_numbers, itog_numbers.begin()));
    if (itog_numbers.empty() == true){
        cout << "Цифр, которые встречаются в двухзначных и не встречаются в трёхзначных нет";
    }
    else{
        for(set<char>::iterator it = itog_numbers.begin(); it != itog_numbers.end(); it++){
            cout << *it << " ";
        }
    }
    return 0;
}
