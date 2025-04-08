# include <iostream>
# include <string>
using namespace std;
int main(){
    string str;
    getline(cin, str);
    string::size_type i{0}, j{0};
    while(true){
        j = str.find_first_of(",.!?;: ", i);
        if(j != string::npos){
            if(!str.substr(i, j-i).empty()){
                cout << str.substr(i, j-i) << endl;
            }
            i = j + 1;
        }
        else {
            if(!str.substr(i, j-i).empty()){
                cout << str.substr(i, j-i) << endl;
            break;
            }

    }
    }

}
// Leave out all the resti The Catalyst, Breaking the habit.
// КОСМОС