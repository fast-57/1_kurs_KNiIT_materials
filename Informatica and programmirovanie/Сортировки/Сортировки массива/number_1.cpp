#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<vector<int>> readMatrix(const string& filename) {
    ifstream inFile(filename);
    vector<vector<int>> matrix;
    
    string line;
    while (getline(inFile, line)) {
        vector<int> stroka;
        size_t pos = 0;
        while (pos < line.length()) {
            size_t probel_pos = line.find(' ', pos);
            if (probel_pos == string::npos) probel_pos = line.length();
            
            string num_str = line.substr(pos, probel_pos - pos);
            stroka.push_back(stoi(num_str));
            pos = probel_pos + 1;
        }
        matrix.push_back(stroka);
    }
    inFile.close();
    return matrix;
}

// сортировка кучи для пирамидальной сортировки
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
// Пирамидальная сортировка
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Построение кучи (перегруппируем массив)
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(arr, n, i);

    // Один за другим извлекаем элементы из кучи
    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Функция для сортировки столбцов матрицы
void sort_stolbci(vector<vector<int>>& matrix) {
    int stroki = matrix.size();
    int stolbci = matrix[0].size();

    for (int j = 0; j < stolbci; ++j) {
        vector<int> column;
        // Собираем столбец
        for (int i = 0; i < stroki; ++i) {
            column.push_back(matrix[i][j]);
        }
        // Сортируем столбец
        heapSort(column);
        // Записываем отсортированный столбец обратно в матрицу
        for (int i = 0; i < stroki; ++i) {
            matrix[i][j] = column[i];
        }
    }
}

void writeMatrix(const string& filename, const vector<vector<int>>& matrix) {
    ofstream outFile(filename);
    
    for(size_t i = 0; i < matrix.size(); i++){
        for(size_t j = 0; j < matrix[i].size(); j++){
            outFile << matrix[i][j];
            if (j != matrix.size() - 1){
                outFile << " ";
            }
        }
        outFile << endl;
    }
    outFile.close();
}

int main() {
    string inputFile = "Matrix.txt", outputFile = "sort_matrix.txt";
    
    vector<vector<int>> matrix = readMatrix(inputFile);

    // Сортируем каждый столбец пирамидальной сортировкой
    sort_stolbci(matrix);

    writeMatrix(outputFile, matrix);
    cout << "Отсортированная матрица сохранена в " << outputFile << endl;

    return 0;
}