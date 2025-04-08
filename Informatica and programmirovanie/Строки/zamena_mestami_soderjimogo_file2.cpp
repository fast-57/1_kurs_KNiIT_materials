# include <iostream>
# include <string>
# include <iomanip>
# include <fstream>
# include <windows.h>
using namespace std;
int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int a1 = 1, a2 = 1, a, n = 10;
    ofstream out("data.dat", ios_base::binary);
    out.write((char*)&a1, sizeof(a1));
    out.write((char*)&a2, sizeof(a2));
    for (int i = 2; i < n; i++){
        a = a1 + a2;
        a1 = a2;
        a2 = a;
        out.write((char*)&a, sizeof(a));
    }
    out.close();
    ifstream in("data.dat", ios_base::binary);
    in.seekg(2*sizeof(a));
    while(in.peek() != EOF){
        in.read((char*)&a, sizeof(a));
        cout << a << endl;
        in.seekg(2*sizeof(a), ios_base::cur);
    }
    return 0;
}