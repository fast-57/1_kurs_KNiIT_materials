#include<iostream>
#include <fstream>
#include<string>
using namespace std;

int main() {
    ifstream in("input.txt"); 
    ofstream out("output.txt"); 
    string str, n;
    int k;
    getline(in, str);
    str += ' ';
    string::size_type l = 0, r = str.find(". "), o; 
    string predl = str.substr(l, r - l);

    while (l != string::npos) {
        l = str.find(". ", r); 
        r = str.find(". ", l + 1); 
        predl = str.substr(l + 2, r - l - 2);
        string::size_type q = predl.find_first_of(".");
        if (q != string::npos){
            for (int i = q - 2; i < q + 8; i++){
                out << predl[i];
            }
            out << "\n";
        }
        for (int i = 1; i < 13; i++){
            k = i;
            switch(k){
                case 1:{
                    n = "January";
                    break;
                }
                case 2: {
                    n = "February";
                    break;
                }
                case 3:{
                    n = "March";
                    break;
                }
                case 4:{
                    n = "April";
                    break;
                }
                case 5:{
                    n = "May";
                    break;
                }
                case 6:{
                    n = "June";
                    break;
                }
                case 7:{
                    n = "Jule";
                    break;
                }
                case 8:{
                    n = "August";
                    break;
                }
                case 9:{
                    n = "September";
                    break;
                }
                case 10:{
                    n = "October";
                    break;
                }
                case 11:{
                    n = "November";
                    break;
                }
                case 12:{
                    n = "December";
                    break;
                }
            }
            o = predl.find(n);
            if (o != string::npos){
                for (int j = o - 3; j < (o + n.length() + 5); j++){
                    out << predl[j];
                }
                out << "\n";
            }

    }

    }
    in.close();
    out.close();
}