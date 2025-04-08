# include <iostream>
# include <string>
# include <iomanip>
# include <fstream>
# include <windows.h>
using namespace std;
int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    string x;
    ifstream in("file_io.txt");
    ofstream out("buffer.txt");
    while (in.peek() != EOF){
        in >> x;
        out << x << endl;
    }
    in.close();
    out.close();
    ifstream in1("file_oi.txt");
    ofstream out1("file_io.txt");
    while(in1.peek() != EOF){
        in1 >> x;
        out1 << x << endl;
    }
    in1.close();
    out1.close();
    ifstream in2("buffer.txt");
    ofstream out2("file_oi.txt");
    while (in2.peek() != EOF){
        in2 >> x;
        out2 << x << endl;
    }
    in2.close();
    out2.close();
    return 0;
}