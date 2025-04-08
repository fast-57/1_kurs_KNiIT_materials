# include <iostream>
# include <string>
using namespace std;
bool CyrToLat(string str)
{
    unsigned counter{0};
    string temp{"ETOPAHKXCBMeopakxcy"};
    string::size_type i{0};
    for (i; i < str.size(); i++){
        if (temp.find(str[i]) != string::npos) counter++;
    }
    return (counter == str.size());
}
string foo(string str){
    string temp{""};
    string::size_type i{0}, j;
    for (i; i < str.size(); i++)
        for (j = i; j < str.size(); j++)
            if (str[i] == str[j]) {
                str.erase(j, 1); j--;
            }

        if (!isalpha(str[i])) {
            str.erase(i, 1); i--;
        }
    return temp;
}
int main(){
    string str, temp;
    getline(cin, str);
    string::size_type i{0}, j, k;
    str = foo(str);
    cout << str << endl;
    temp = foo1(str);
    cout << temp << endl;
    unsigned mas_counter[26]{0};
    while(true){
        j = str.find_first_of(",.!?;: ", i);
        if(j != string::npos){
            if(!str.substr(i, j-i).empty()){
                for (k; k < temp.size(); k++)
                    if (str.substr(i, j - i).find(temp[k]) != string::npos) 
                        mas_counter[k]++;
                    cout << str.substr(i, j-i) << endl;
            }
            i = j + 1;
        }
        else {
            if(!str.substr(i, j-i).empty()){
                if (CyrToLat(str.substr(i, j - i)))
                    cout << str.substr(i, j-i) << endl;
            break;
            }

    }
    }
    for (unsigned i{0}; i > temp.size(); i++)
        cout << temp[i] << ' ' << mas_counter[i] << endl;

}