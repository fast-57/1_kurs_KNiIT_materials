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

// сортировка кучи для пирамидальной сортировки
void heap(vector<rabotnick>& rabotniki, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && rabotniki[left].post > rabotniki[largest].post)
        largest = left;

    if (right < n && rabotniki[right].post > rabotniki[largest].post)
        largest = right;

    if (largest != i) {
        swap(rabotniki[i], rabotniki[largest]);
        heap(rabotniki, n, largest);
    }
}

// Пирамидальная сортировка
void heapSort(vector<rabotnick>& rabotniki) {
    int n = rabotniki.size();

    // Построение кучи (перегруппировка массива)
    for (int i = n / 2 - 1; i >= 0; i--)
        heap(rabotniki, n, i);

    // сортировка массива
    for (int i = n - 1; i > 0; i--) {
        swap(rabotniki[0], rabotniki[i]);
        heap(rabotniki, i, 0);
    }
}

void read_file(const string& filename, vector<rabotnick>& rabotniki) {
    ifstream file(filename);

    rabotnick emp;
    while (file >> emp.familia >> emp.post >> emp.birthDay >> emp.birthMonth >> emp.birthYear >> emp.opit >> emp.zarplata) {
        rabotniki.push_back(emp);
    }

    file.close();
}

void write_to_file(const string& filename, const vector<rabotnick>& rabotniki) {
    ofstream file(filename);
    int n = rabotniki.size();
    for (int i = 0; i < n; i++) {
        const rabotnick& emp = rabotniki[i];
        file << emp.familia << " " << emp.post << " " 
             << emp.birthDay << "." << emp.birthMonth << "." << emp.birthYear << " " 
             << emp.opit << " " << emp.zarplata << endl;
    }

    file.close();
}

int main() {
    vector<rabotnick> rabotniki;
    string inputFilename = "data.txt";
    string outputFilename = "sorted_data.txt";
    
    read_file(inputFilename, rabotniki);
    heapSort(rabotniki);
    write_to_file(outputFilename, rabotniki);
    return 0;
}