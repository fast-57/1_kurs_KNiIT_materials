#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<vector>    
#include<ctime> 
#include<windows.h>
using namespace std;

struct Train {
    int trainNumber;
    string departureDate; // дата отправления
    string departureTime; // время отправления
    int travelTimeMinutes; // время пути
};

bool isValidDate(const string& date) {  // проверка корректности даты 
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') 
        return false;
    try {
        int year = stoi(date.substr(0, 4)); // преобразуем в число
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        if (month < 1 || month > 12 || day < 1 || day > 31) 
            return false;
        if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) 
            return false;
        if (month == 2) { 
            bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0); // Проверка, является ли год високосным
            if ((isLeapYear && day > 29) || (!isLeapYear && day > 28)) 
                return false;
        }
        return true;
    } catch (...) {
        return false;
    }
}

string calculateArrivalTime(const Train& train) {     // вычисление времени прибытия
    // данные о времени отправления
    int hour = stoi(train.departureTime.substr(0, 2));
    int minute = stoi(train.departureTime.substr(3, 2));
    int travelMinutes = train.travelTimeMinutes;
    // добавляем время в пути
    minute += travelMinutes;
    hour += minute / 60;
    minute %= 60;

    hour %= 24;
    return (hour < 10 ? "0" : "") + to_string(hour) + ":" + (minute < 10 ? "0" : "") + to_string(minute);
}

bool arrivesSameDay(const Train& train) { // прибывает ли поезд в тот же день
    int hour = stoi(train.departureTime.substr(0, 2));
    int minute = stoi(train.departureTime.substr(3, 2));
    int travelMinutes = train.travelTimeMinutes;

    minute += travelMinutes;
    hour += minute / 60;
    return (hour / 24) == 0; 
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    vector<Train> trains = { // создаём список поездов через динамический массив
        {101, "2024-12-22", "14:30", 300},
        {102, "2024-12-22", "20:15", 90},
        {103, "2024-12-22", "23:50", 20},
    };

    cout << "Поезда, прибывающие в тот же день:" << endl;

    for (const auto& train : trains) {
        if (isValidDate(train.departureDate) && arrivesSameDay(train)) {
            cout << "Номер поезда: " << train.trainNumber
                 << ", Дата отправления: " << train.departureDate
                 << ", Время отправления: " << train.departureTime
                 << ", Время прибытия: " << calculateArrivalTime(train)
                 << endl;
        } else if (!isValidDate(train.departureDate)) {
            cout << "Неверная дата для поезда №" << train.trainNumber << endl;
        }
    }

    return 0;
}
