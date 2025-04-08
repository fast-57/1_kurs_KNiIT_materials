#include <iostream>
#include <time.h>

using namespace std;

int** input(int n, int m){ // Returns matrix (n*m) with parameters that are chosen by you
    int x;
    int** mas = new int*[2*n];
    for (int i = 0; i<n; ++i)
	    mas[i] = new int[2*m];

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; j++){
            cout << "mas[" << i << "][" << j << "] = ";
            cin >> x;
            mas[i][j] = x;
        }
    }
    return mas;
}

int** rand_input(int n, int m){ // n - len of 1 array from matrix. Returns matrix (n*n) with random parameters 
    int x;
    int** mas = new int*[2*n];
    for (int i = 0; i<n; ++i)
	    mas[i] = new int[2*m];
    srand(time(0));
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; j++){
            mas[i][j] = rand() %10;
        }
    }
    return mas;
}

void printArray(int** array, int rows, int cols) {
    // Output an array
    for (int i = 0; i < rows; i++, cout << endl) {
        for (int j = 0; j < cols; j++) {
            cout << array[i][j] << " ";
        }
    }
}

void deleteArray(int **array, int rows) {
    for (int i = 0; i < rows; i++) {
        delete [] array[i];
    }
    delete [] array;
}

int main() {
    setlocale(LC_ALL, "RUS");
    int rows, cols;
    cout << "Введите размерность матрицы (n x m)\n";
    cin >> rows >> cols;

    int** array;
    array = input(rows,cols);

    cout << "Полученная матрица:\n";
    printArray(array, rows, cols);
    
    // Finding target rows
    int* target;
    for (int i = 0; i < rows; ++i) {
        bool flag = true;
        for (int j = 0; j < cols; ++j) {
            if (array[i][j] % 2 == 0) {
                flag = false;
                break;
            }
        }

        if (flag) {
            target = array[i];
            // Resize array
            rows++;
            // Shift rows
            for (int k = rows - 1; k > i + 1; --k) {
                array[k] = array[k - 1];
            }

            // Insert new row
            array[i + 1] = target;
            i++; // Skip inserted row
        }
    }
    cout << "Ответ:\n";
    printArray(array, rows, cols);
    deleteArray(array, rows);
}



