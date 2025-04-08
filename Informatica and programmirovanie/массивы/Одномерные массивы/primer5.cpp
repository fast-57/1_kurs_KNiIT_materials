# include <iostream>
using namespace std;
int main(){
    int n = 5, i = 1;
    int *mas = new int [n];
    for (int i = 0; i < n; i++){
        mas[i] = i + 1;
        cout << "mas[" << i << "]=" << mas[i] << endl;
        cout << "adress" << &(mas[i]) << endl;
    }
    delete [] mas;
    return 0;
}