#include<iostream>
#include<string>
# include <windows.h>
using namespace std;

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    string str;
    string sep = ".,:;!?- ";
    string let = "ETOPAHKXCBMeyopaxc";
    cout << "Введите строку ";
    getline(cin, str); 
    str += ' '; 

    string::size_type l, r;
    l = str.find_first_not_of(sep);

    while (l != string::npos) {
        r = str.find_first_of(sep, l); 
        string word = str.substr(l, r - l);
        if (word.find_first_not_of(let) == string::npos) 
            cout << word << '\n';
            l = str.find_first_not_of(sep, r); 
    }
}