# include <iostream>
# include <windows.h>
using namespace std;
int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int n;
    cout << "Введите длину массива: "; cin >> n;
    int *mas = new int(n);
    for (int i = 0; i < n; i++){
        cout << "Введите элемент массива: ";
        cin >> mas[i];
    }
    for (int i = 0; i < n; ){
        if (mas[i] % 2 == 0){
            n--;
            for (int j = i; j < n; j++){
                mas[j] = mas[j + 1];
            }
        }
        else{
            i++;
        }
    }
    for (int i = 0; i < n; i++)
        cout << mas[i] << " ";
    return 0;
}