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
// Сортировка вставками для вектора
void insertionSort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Функция для сортировки диагоналей, параллельных побочной
void sortSecondaryDiagonals(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // Сортировка диагоналей выше побочной
    for (int d = 0; d < n; ++d) {
        vector<int> diagonal;
        for (int i = 0, j = d; i < n && j >= 0; ++i, --j) {
            if (i + j != n - 1) {  // Исключаем побочную диагональ
                diagonal.push_back(matrix[i][j]);
            }
        }
        insertionSort(diagonal);
        int k = 0;
        for (int i = 0, j = d; i < n && j >= 0; ++i, --j) {
            if (i + j != n - 1) {
                matrix[i][j] = diagonal[k++];
            }
        }
    }

    // Сортировка диагоналей ниже побочной
    for (int d = 1; d < n - 1; ++d) {
        vector<int> diagonal;
        for (int i = d, j = n - 1; i < n && j >= 0; ++i, --j) {
            if (i + j != n - 1)
            diagonal.push_back(matrix[i][j]);
        }
        insertionSort(diagonal);
        int k = 0;
        for (int i = d, j = n - 1; i < n && j >= 0; ++i, --j) {
            matrix[i][j] = diagonal[k++];
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

    // Сортировка диагоналей
    sortSecondaryDiagonals(matrix);

    writeMatrix(outputFile, matrix);
    cout << "Отсортированная матрица сохранена в " << outputFile << endl;

    return 0;
}