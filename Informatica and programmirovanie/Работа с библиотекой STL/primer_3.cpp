# include <iostream>
# include <set>
# include <map>
# include <algorithm>
# include <string>
# include <fstream>
# include <iostream>
# include <windows.h>
using namespace std;
int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    map<string, int> let;
    map<string, int> num;
    ifstream in("text_primer.txt");
    string number;
    string ch;
    string word;
    while(in >> word){
        for(string::size_type i = 0; i < word.size(); i++){
            if (isdigit(word[i])){
                number += word[i];
            }
        }
    }
    string firstWord;
    while (in.peek() != EOF){
        in >> word;
        if (word.find_first_not_of(number) != string::npos){
            num[word]++;
        }
        else{
            if (let.size() == 0){
                firstWord = word;
            }
            let[word]++;
        }
    }
    int p = let[firstWord];
    for(auto it = let.begin(); it != let.end(); ++it){
        if (it -> second < p){
            cout << it->first;
        }
    }
    }
