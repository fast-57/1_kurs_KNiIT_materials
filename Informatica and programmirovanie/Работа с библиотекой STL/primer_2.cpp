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
            for(string::size_type i = 0; i < word.length(); i++){
                if (isupper(word[i])){
                    word[i] = tolower(word[i]);
                }
            }
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
    vector<string>res(vopr.size());
    set_difference(vopr.begin(), vopr.end(), vosk.begin(), vosk.end(), res.begin());
    for(string::size_type i = 0; i < res.size(); i++){
        cout << res[i] << endl;
    }
}