# include <iostream>
# include <string>

using namespace std;

struct date{
    int day;
    int month;
    int year;
};

date STR_date(string str){
    date data;
    string str1 = str.substr(0, 2);
    const char *sd = str1.c_str();
    int dd = atoi(sd);
    data.day = dd;
    str1 = str.substr(3, 2);
    sd = str1.c_str();
    dd = atoi(sd);
    data.month = dd;
    str1 = str.substr(6, 4);
    sd = str1.c_str();
    dd = atoi(sd);
    data.year = dd;

    return data;
}

bool vis(int y){
    return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}

int EndOfMonth(int m, int y){
    switch(m){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
        case 4: case 6: case 9: case 11: return 30;
        case 2: if (vis(y)) return 29;
            else return 28;
    }
}

date Next(date x){
    date y = x;
    if (x.day < EndOfMonth(x.month, x.year)) y.day = x.day + 1;
    else if (x.month < 12){
        y.day = 1;
        y.month = x.month + 1;
    }
    else{
        y.day = 1;
        y.month = 1;
        y.year = x.year + 1;
    }
    return y;
}

void print(date x){
    if (x.day < 10) cout << "0" << x.day << ".";
    else cout << x.day << ".";
    if (x.month < 10) cout << "0" << x.month << ".";
    else cout << x.month << ".";
    if (x.year < 10) cout << "000" << x.year;
    else if (x.year < 100) cout << "00" << x.year;
    else if (x.year < 1000) cout << "0" << x.year;
    else cout << x.year;
    cout << endl;
}

int correct(string str){
    if (str.length() != 10) return -1;
    for(string::size_type i = 0; i < str.length(); i++)
        if (i != 2 && i != 5){
            if (!isdigit(str[i])) return -1;
        }
        date data = STR_date(str);
        if (data.day <= 0 || data.day > EndOfMonth(data.month, data.year)) return -2;
        if (data.month <= 0 || data.month > 12) return -3;
        if (data.year == 0) return -4;
    return 1;
}

int main(){
    string str;
    cout << "Input date as dd.mm.yyyy\n";
    getline(cin, str);
    int fl = correct(str);
    if (fl == -1) cout << "Error input\n";
    else if (fl == -2) cout << "Error day\n";
    else if (fl == -3) cout << "Error month\n";
    else if (fl == -4) cout << "Error year\n";
    else{
        date data = STR_date(str);
        date N_date = Next(data);
        print(N_date);
    }
    return 0;
}