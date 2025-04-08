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

// Функция для слияния двух подмассивов
void Merge(vector<rabotnick>& rabotniki, int left, int right) {
    int middle, start, final, j;
    vector<rabotnick> temp(right - left + 1); // Временный массив для хранения данных
    middle = (left + right) / 2;
    start = left; final = middle + 1;

    for (j = left; j <= right; j++) {
        if ((start <= middle) && ((final > right) || 
            (rabotniki[start].zarplata < rabotniki[final].zarplata || 
             (rabotniki[start].zarplata == rabotniki[final].zarplata && 
              rabotniki[start].birthYear < rabotniki[final].birthYear)))) {
            temp[j - left] = rabotniki[start];
            start++;
        } else {
            temp[j - left] = rabotniki[final];
            final++;
        }
    }

    // Копируем отсортированные данные обратно в основной массив
    for (j = left; j <= right; j++) {
        rabotniki[j] = temp[j - left];
    }
}

// Рекурсивная функция для сортировки слиянием
void Sort(vector<rabotnick>& rabotniki, int left, int right) {
    if (left < right) {
        Sort(rabotniki, left, (left + right) / 2); // сортировка левой части
        Sort(rabotniki, (left + right) / 2 + 1, right); // сортировка правой части
        Merge(rabotniki, left, right); // слияние двух частей
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

    
    Sort(rabotniki, 0, rabotniki.size() - 1);

   
    ofstream outputFile(outputFilename);

    for (const auto& emp : rabotniki) {
        outputFile << emp.familia << " " << emp.post << " "
                   << emp.birthDay << "." << emp.birthMonth << "." << emp.birthYear << " "
                   << emp.opit << " " << emp.zarplata << endl;
    }
    outputFile.close();

    return 0;
}