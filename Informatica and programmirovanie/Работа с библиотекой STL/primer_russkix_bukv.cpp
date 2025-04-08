#include <iostream>
#include <vector>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    vector<bool> alphabetRus(33, true);

    cout << "Русские буквы: ";
    for (int i = 0; i < 33; i++) {
        char bukva;
        if (i == 6) {
            bukva = 'ё';
        } else if (i < 6) {
            bukva = 'а' + i;
        } else {
            bukva = 'а' + i - 1;
        }
        if (alphabetRus[i]) {
            cout << bukva << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;

    return 0;
}