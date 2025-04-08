# include <iostream>
# include <windows.h>
using namespace std;
int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
	int n, m;
    cout << "n = "; cin >> n;
    cout << "m = "; cin >> m;
	int* a = new int[n + 1];
	for (int i = 0; i < n + 1; i++) {
        cout << "Коэффициенты P(x): ";
		cin >> a[i];
	}
	cout << endl;
	int *b = new int[m + 1];
	for (int i = 0; i < m + 1; i++) {
        cout << "Коэффициенты Q(x): ";
		cin >> b[i];
	}
	cout << endl;
    int *c = new int[n + m + 1];
	for (int i = 0; i < n + m + 1; i++) {
        c[i] = 0;
	}
	for (int i = 0; i < n + 1; i++){
		for (int j = 0; j < m + 1; j++) {
			c[i+j] += a[i] * b[j];
		}
	}
	for (int i = 0; i < n + m + 1; i++) {
		cout << c[i] << " ";
	}
}