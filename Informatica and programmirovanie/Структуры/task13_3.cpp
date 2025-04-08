#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<windows.h>
using namespace std;

struct Time { 
    int hour = 0, minute = 0, second = 0;
    int checkTime() { // проверка корректности времени
        if (!(0 <= minute && minute < 60) ||
        !(0 <= second && second < 60)) return 1;
        return 0;
    }
    void printTime() { 
        cout << setw(2) << setfill('0') << hour << ':';
        cout << setw(2) << setfill('0') << minute << ':';
        cout << setw(2) << setfill('0') << second << ' ';
    }
    int passedSec () { 
        return second + minute*60 + hour*3600;
    }
    int passedMin () { 
        return minute + hour*60;
    }
    int passedHou () { 
        return hour;
    }
};

Time strToTime(string str) { // перевод со строки во время
    Time t;
    int k = 0;
    for (string::size_type i = 0; i < str.size(); i++) 
        if (str[i] == ':') k++;
    string::size_type r = str.find(':');
    if (k == 1) {
        t.hour = stoi(str.substr(0, r));
        t.minute = stoi(str.substr(r + 1, str.size() - r));
        t.second = 0;
        return t;
    }
    string::size_type l = str.rfind(':');
    t.hour = stoi(str.substr(0, r));
    t.minute = stoi(str.substr(r + 1, l - 1 - r));
    t.second = stoi(str.substr(l + 1, str.size() - l));
    return t;
}

Time afterN(Time t, int n) { // время после n ctreyl
    if (n >= 3600) {
        t.hour += n/3600;
        n = n%3600;
    }
    if (n >= 60) {
        t.minute += n/60;
        n = n%60;
    }
    if (n > 0) t.second += n;
    if (t.second > 59) {
        t.minute += t.second/60;
        t.second = t.second%60;
    }
    if (t.minute > 59) {
        t.hour += t.minute/60;
        t.minute = t.minute%60;
    }
    return t;
}

Time beetween(Time t1, Time t2) { // сколько прошло времени между событиями
    Time t, t0;
    if (t1.passedSec() < t2.passedSec()) {
        t = afterN(t0, t2.passedSec() - t1.passedSec());
    }
    else t = afterN(t0, t1.passedSec()- t2.passedSec());
    return t;
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    char status;
    do {
        cout << "1 - Количество прошедших секунд\n";
        cout << "2 - Количество прошедших минут\n";
        cout << "3 - Количество прошедших часов\n";
        cout << "4 - Время после N секунд\n";
        cout << "5 - Время является правильным?\n";
        cout << "6 - Какова продолжительность между двумя событиями?\n>> ";
        cin >> status;

        int f = 0;
        switch (status) {
            case '1': {
                string stime;
                cout << "Введите время: ";
                cin >> stime; 
                Time t = strToTime(stime); 
                if (t.checkTime()) { 
                    cout << "Неправильное время\n";
                    break;
                }
                cout << "Прошло " << t.passedSec() << " секунд\n";
                break;
            }
            case '2': {
                string stime;
                cout << "Введите время: ";
                cin >> stime; 
                Time t = strToTime(stime); 
                if (t.checkTime()) { 
                    cout << "Неправильное время\n";
                    break;
                }
                cout << "Прошло " << t.passedMin() << " минут\n";
                break;
            }
            case '3': {
                string stime;
                cout << "Введите время: ";
                cin >> stime;
                Time t = strToTime(stime); 
                if (t.checkTime()) { 
                    cout << "Неправильное время\n";
                    break;
                }
                cout << "Прошло " << t.passedHou() << " часов\n";
                break;
            }
            case '4': {
                string stime;
                cout << "Введите время: ";
                cin >> stime; 
                Time t = strToTime(stime); 
                if (t.checkTime()) { 
                    cout << "Неправильное время\n";
                    break;
                }
                int n;
                cout << "Введите N: ";
                cin >> n;
                cout << "Время после " << n << " секунд: ";
                afterN(t, n).printTime();
                cout << '\n';
                break;
            }
            case '5': {
                string stime;
                cout << "Введите время: ";
                cin >> stime; 
                Time t = strToTime(stime); 
                if (t.checkTime()) cout << "Время указано неверно\n";
                else cout << "Время указано верно\n";
                break;
            }
            case '6': {
                string stime;
                cout << "Введите первое время: ";
                cin >> stime; 
                Time t1 = strToTime(stime); 
                if (t1.checkTime()) {  
                    cout << "Время указано неверно\n";
                    break;
                }

                cout << "Введите второе время: ";
                cin >> stime; 
                Time t2 = strToTime(stime); 
                if (t2.checkTime()) { 
                    cout << "Время указано неверно\n";
                    break;
                }
                beetween(t1, t2).printTime();
                cout << '\n';
                break;
            }
            default: f = 1;
        }
        
        if (f) status = 'y';
        else {
            cout << "Ещё раз? (y/n) ";
            cin >> status;
        }
    } while (status == 'y' && status != 'Y');
}