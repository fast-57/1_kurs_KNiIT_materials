# include <iostream>
# include <set>
# include <map>
# include <algorithm>
# include <string>
# include <fstream>
# include <iostream>
# include <windows.h>
using namespace std;
bool prover_stroka_or_number(string str){
    for(int i = 0; i < str.length(); i++){
        if (!isdigit(str[i])){
            return false;
        }
    }
    return true;
}

int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    map<string, int> kolvo_slov;
    ifstream in("text_primer.txt");
    string word;
    int firstNumber = -1;
    int firstNumberCount = 0;
    while(in >> word){
        if (prover_stroka_or_number(word)){
            int number = stoi(word);
            if (firstNumber == -1){
                firstNumber = number;
                firstNumberCount = 1;
            }
            else if (number == firstNumber){
                firstNumberCount++;
            }
        }
        else{
            kolvo_slov[word]++;
        }
    }
    
    for (map<string, int>::iterator it = kolvo_slov.begin(); it != kolvo_slov.end(); it++){
        if(it->second == firstNumberCount){
            cout << it->first << endl;
        }
    }
    return 0;
    }
