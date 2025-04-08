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
int main(){
    string str;
    getline(cin, str);
    string::size_type i{0}, j{0};
    while(true){
        j = str.find_first_of(",.!?;: ", i);
        if(j != string::npos){
            if(!str.substr(i, j-i).empty()){
                if (CyrToLat(str.substr(i, j - i)))
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

}
// КОСМОС, gfd, сахар, метро