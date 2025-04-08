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
// Функция слияния для сортировки по возрастанию
void sort_by_vozr(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Функция слияния для сортировки по убыванию
void sort_by_ybiv(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Сортировка слиянием (по возрастанию)
void sort_slianiem_by_vozr(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        sort_slianiem_by_vozr(arr, left, mid);
        sort_slianiem_by_vozr(arr, mid + 1, right);
        sort_by_vozr(arr, left, mid, right);
    }
}

// Сортировка слиянием (по убыванию)
void sort_sliyaniem_by_ybiv(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        sort_sliyaniem_by_ybiv(arr, left, mid);
        sort_sliyaniem_by_ybiv(arr, mid + 1, right);
        sort_by_ybiv(arr, left, mid, right);
    }
}

// Функция для сортировки строк матрицы
void sort_stroki(vector<vector<int>>& matrix) {
    for (size_t i = 0; i < matrix.size(); ++i) {
        if ((i + 1) % 3 == 0) {  // Каждая третья строка (индексы 2, 5, 8...)
                sort_sliyaniem_by_ybiv(matrix[i], 0, matrix[i].size() - 1);
        } else {  // Все остальные строки
            if (!matrix[i].empty()) {
                sort_slianiem_by_vozr(matrix[i], 0, matrix[i].size() - 1);
            }
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

    // Сортировка строк
    sort_stroki(matrix);

    writeMatrix(outputFile, matrix);
    cout << "Отсортированная матрица сохранена в " << outputFile << endl;

    return 0;
}