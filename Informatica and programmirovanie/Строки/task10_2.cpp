# include <iostream>
# include <string>
using namespace std;

int main(){
    string s1, smax, smin ,s2 = " ";
    string razdel = "!?,.:;- ";
    string::size_type pos1 = 0, pos2 = 0, z;
    getline(cin, s1);
    s1 += '.';
    string::size_type pos = 0, k;
    string::size_type max = 0, min = INT_MAX;
    k = s1.find_first_of(razdel);
    while(k != string::npos){
        string word = s1.substr(pos, k - pos);
        if (word.length() > max){
            max = word.length();
            smax = word;
        }
        if (ispunct(s1[k])) pos = k + 2;
        else pos = k + 1;
        k = s1.find_first_of(razdel, pos);
    }
    pos = 0;
    k = s1.find_first_of(razdel);
    while (k != string::npos){
        string word = s1.substr(pos, k - pos);
        if (word.length() < min){
            min = word.length();
            smin = word;
        }
        if (ispunct(s1[k])) pos = k + 2;
        else pos = k + 1;
        k = s1.find_first_of(razdel, pos);
    }
    cout << "max word " << smax << endl;
    cout << "min word " << smin << endl;
    cout << s1 << "\n";
    
    pos1 = s1.find(smax);
    pos2 = s1.find(smin);
    if (pos1 > pos2){
        s2.append(s1, 0, pos2);
        s2.append(smax);
        cout << s2 << "\n";
        s2.append(s1, (pos2 + smin.length()), pos1 - (pos2 + smin.length()));
        cout << s2 << "\n";
        s2.append(smin);
    }
    else{
        s2.append(s1, 0, pos1);
        s2.append(smin);
        s2.append(s1, (pos1 + smax.length()), pos2 - (pos1 + smax.length()));
        s2.append(smax);
        z = pos1 + smax.length() + smin.length() + 1;
        if (s1[z + 1] == ',' or s1[z + 1] == '.'){
            z += 2;
        }
        else{
            z += 1;
        }
        s2.append(s1, z, string::npos);
    }
    cout << s2;
    return 0;
}