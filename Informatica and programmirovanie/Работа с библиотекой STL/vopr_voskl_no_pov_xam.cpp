# include <iostream>
# include <set>
# include <algorithm>
# include <string>
using namespace std;
string to_lower(string str)
{
    for(int i {0}; i < str.size(); i++)
        str[i] = tolower(str[i]);
    return str;
}
set<string> to_set(string str)
{
    set <string> set_word;
    if (str[str.size() - 1] != ' ') str += " ";
    while(str != "")
    {
        set_word.insert(to_lower(str.substr(0, str.find(' '))));
        str.erase(0, str.find(' ') + 1);
    }
    return set_word;
}

int main(){
    set <string> temp, voskl, vopr, pov, res1, res2;
    string str;
    getline(cin, str);
    while(str != "")
    {
        int pos{str.find_first_of("!?.")};
        temp = to_set(str.substr(0, pos));
        if(str[pos] == '!') voskl.insert(temp.begin(), temp.end());
        if(str[pos] == '?') vopr.insert(temp.begin(), temp.end());
        if(str[pos] == '.') pov.insert(temp.begin(), temp.end());
        str.erase(0, pos + 2);
    }
    for(auto it = voskl.begin(); it != voskl.end(); it++)
    {
        cout << *it << " ";
    }
    cout << "\n";
    for(auto it = vopr.begin(); it != vopr.end(); it++)
    {
        cout << *it << " ";
    }
    cout << "\n";
    for(auto it = pov.begin(); it != pov.end(); it++)
    {
        cout << *it << " ";
    }
    cout << "\n";
    set_union(voskl.begin(), voskl.end(), vopr.begin(), vopr.end(), inserter(res1, res1.begin()));
    set_difference(res1.begin(), res1.end(), pov.begin(), pov.end(), inserter(res2, res2.begin()));
    for(auto it = res2.begin(); it != res2.end(); it++)
        cout << *it << " ";
}


/* Leave out all the rest! My December? THe Numb! The breaking the habbit. All true. */