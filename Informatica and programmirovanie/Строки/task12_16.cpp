# include <iostream>
# include <string>
# include <iomanip>
# include <fstream>
# include <windows.h>
using namespace std;
int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    string str;
    ifstream in("input.txt");
    ofstream out("output.txt");
    string::size_type l, r;
    getline(in, str);
    l = str.find_first_not_of(". "); // позиция первой буквы в первом предложении
    while (l != string::npos) {
        r = str.find_first_of(". ", l); // позиция первого символа в строке не в первом слове после l-ого символа
        string predl = str.substr(l, r - l); // одно предложение
        cout << predl << '\n';
        l = str.find_first_not_of(". ", r); // позиция первой буквы в первом предложении после r-ого символа
    }
    in.close();
    out.close();
    return 0;
}