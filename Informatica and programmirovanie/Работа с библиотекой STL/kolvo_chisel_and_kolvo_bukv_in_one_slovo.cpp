# include <iostream>
# include <map>
# include <string>
# include <fstream>
using namespace std;
bool number(string s){
    for(int i = 0; i < s.length(); i++)
        if(!isdigit(s[i])) return false;
    return true;
}
int main(){
    string slovo;
    map<string, int> word;
    map<string, int> numb;
    string last_numb = "";
    ifstream in("text.txt");
    while(in.peek() != EOF){
        in >> slovo;
        if (number(slovo)){
            last_numb = slovo;
            numb[slovo] ++;
        }
        else{
            word[slovo]++;
        }
    }
    if(last_numb == ""){
        cout << "no words";
        system("pause");
        return 0;
    }
    int k;
    cin >> k;
    for(map<string, int> ::iterator i = word.begin(); i != word.end(); i++){
        if (i->second == numb[last_numb])
            cout << i->first << " ";
    }
    return 0;
}