# include <iostream>
# include <set>
# include <vector>
# include <algorithm>
# include <string>
# include <windows.h>
using namespace std;
int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    set<string>vopr;
    set<string>vosk;
    set<string>pov;
    string str;
    getline(cin, str);
    string razd = "!?.";
    string::size_type pos = 0;
    while (pos < str.length())
    {
        string::size_type k = str.find_first_of(razd, pos);
        if (k == string::npos) break;
        char tmp = str[k];
        string temp = str.substr(pos, k - pos) + " ";
        string::size_type pos1 = 0;
        while(pos1 < temp.length())
        {
            string::size_type k1 = temp.find_first_of(" ", pos1);
            if (k1 == string::npos) break;
            string word = temp.substr(pos1, k1 - pos1) + " ";
            switch(tmp){
                case '?':
                    vopr.insert(word);
                    break;
                case '!':
                    vosk.insert(word);
                    break;
                default:
                    break;
            }
            pos1 = k1 + 1;
        }
        pos = k + 1;

    }
    set<string> vopr_vosk;
    set_union(vopr.begin(), vopr.end(), vosk.begin(), vosk.end(), inserter(vopr_vosk, vopr_vosk.begin()));
    vector<string>res;
    set_difference(vopr_vosk.begin(), vopr_vosk.end(), pov.begin(), pov.end(), back_inserter(res));
    for(string::size_type i = 0; i < res.size(); i++){
        cout << res[i] << endl;
    }
}