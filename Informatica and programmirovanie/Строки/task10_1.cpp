# include <iostream>
# include <string>
# include <windows.h>
using namespace std;
int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    string s1, s3 = "!", s2 = "bcdfghklmnpqrstvxzBCDFGHKLMNPQRSTVXZ";
    char ch;
    cout << "Введите строку: ";
    cin >> s1;
    string::size_type pos = 0;
    while (!(s3.empty())){
        pos = s1.find_first_of(s2, pos);
        s3 = s1.substr();
        s1.insert(pos + 1, 1, '!');
        pos += 1;
        s3.erase(0, pos);
    }
    cout << "Ответ: " << s1 << endl;
    return 0;
}