#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct rabotnick {
    string familia;
    string post;
    int birthDay, birthMonth, birthYear;
    int opit;
    double zarplata;
};

// Функция для сравнения двух сотрудников по заданным ключам
bool sravnenie(const rabotnick& a, const rabotnick& b) {
    if (a.familia != b.familia)
        return a.familia < b.familia;
    if (a.opit != b.opit)
        return a.opit < b.opit;
    return a.birthYear < b.birthYear;
}

// Сортировка вставками
void Sort(vector<rabotnick>& rabotniki) {
    int n = rabotniki.size();
    for (int i = 1; i < n; i++) {
        rabotnick key = rabotniki[i];
        int j = i - 1;

        // Сдвигаем элементы, которые больше ключа
        while (j >= 0 && sravnenie(key, rabotniki[j])) {
            rabotniki[j + 1] = rabotniki[j];
            j--;
        }
        rabotniki[j + 1] = key;
    }
}

int main() {
    vector<rabotnick> rabotniki;
    string inputFilename = "data.txt";
    string outputFilename = "sorted_data.txt";
    ifstream inputFile(inputFilename);

    rabotnick emp;
    while (inputFile >> emp.familia >> emp.post >> emp.birthDay >> emp.birthMonth >> emp.birthYear >> emp.opit >> emp.zarplata) {
        rabotniki.push_back(emp);
    }
    inputFile.close();

    Sort(rabotniki);

    ofstream outputFile(outputFilename);

    for (const auto& emp : rabotniki) {
        outputFile << emp.familia << " " << emp.post << " "
                   << emp.birthDay << "." << emp.birthMonth << "." << emp.birthYear << " "
                   << emp.opit << " " << emp.zarplata << endl;
    }
    outputFile.close();

    return 0;
}