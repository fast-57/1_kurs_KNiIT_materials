// является ли число степенью двойки
// # include <iostream>
// # include <cmath>
// using namespace std;
// int main(){
//     setlocale(LC_ALL, "RUS");
//     int n;
//     cout << "n = ";
//     cin >> n;
//     (n & (n - 1)) == 0 ? cout << "True" : cout << "False";
//     system("pause");
// }

// решение заданий
# include <iostream>

# include <cmath>
using namespace std;
int main(){
    setlocale(LC_ALL, "RUS");
    int n, i;
    cout << "n = ";
    cin >> n;
    cout << "i = ";
    cin >> i;
    int the_number_one = 2 << (i - 1);   
    cout << "Ответ на 1 задание: " << the_number_one << endl;
    int the_number_two = (1 << i) | n;
    cout << "Ответ на 2 задание: " << the_number_two << endl;
    int the_number_three = ~(1 << i) & n;
    cout << "Ответ на 3 задание: " << the_number_three << endl;
    int the_number_four = (1 << i) ^ n;
    cout << "Ответ на 4 задание: " << the_number_four << endl;
    ((1 & n) == 1) ? cout << "Ответ на 5 задание: " << "Число n является нечётным" : cout << "Ответ на 4 задание: " << "Число n является чётным";
    system("pause");

}