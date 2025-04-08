# include <iostream>
# include <string>
using namespace std;
struct Date{
    unsigned day, month, year;
};
struct Person{
    string name, gender;
    Date dateBirth{ 0, 0, 0 };
    void checkDate(){
        if (dateBirth.day <= 0 || dateBirth.month <= 0 || dateBirth.year <= 0){
            cout << "Date error"; exit(1);
        }
        else if((dateBirth.month == 1 || dateBirth.month == 3 || 
        dateBirth.month == 5 || dateBirth.month == 7 || 
        dateBirth.month == 8 || dateBirth.month == 10 || dateBirth.month == 12) && dateBirth.day > 31)
{
            cout << "Day error"; exit(1);
    }
     else if((dateBirth.month == 4 || dateBirth.month == 6 || 
        dateBirth.month == 9 || dateBirth.month == 11) && dateBirth.day > 30){
            cout << "Day error"; exit(1);
        }
    else if(dateBirth.month == 2){
        if ((!(dateBirth.year%400) || dateBirth.year % 100) && !(dateBirth.year % 4) && dateBirth.day > 29){
            cout << "Day error"; exit(1);
        }
        if ((!(dateBirth.year % 400) || 
        dateBirth.year % 100 && !(dateBirth.year % 4)) && dateBirth.day > 28)
        {
            cout << "Day error"; exit(1);
        }
    }
    else if(dateBirth.month > 12){
        cout << "Month error"; exit(1);
    }
    else cout << "Date correct";
    }
    void readPerson(){
        cin >> name >> gender >> dateBirth.day >> 
            dateBirth.month >> dateBirth.year;
    checkDate();
    }
    unsigned agePerson(Date d){
        if (dateBirth.month > d.month) return d.year - dateBirth.year;
        else if (dateBirth.month == d.month && dateBirth.day <= d.day)
            return d.year - dateBirth.year - 1;
    }
    void writePerson(){
        cout << name <<  ' ' << gender << ' ' << dateBirth.day
    }
};

int main(){
    unsigned n; cin >> n;
    Person *masPerson{new Person[n]};
    for (unsigned i{0}; i < n; i++)
        masPerson[i].readPerson();
    Date d{10, 12, 2024};
    for (unsigned i{0}; i < n; i++)
        if (masPerson[i].agePerson(d) >= 65 && masPerson[i].gender == "m" || masPerson[i].agePerson(d) >= 60 && masPerson[i].gender == "f" || masPerson[i].agePerson(d) >= 65 && masPerson[i].gender == "g" || )
}
