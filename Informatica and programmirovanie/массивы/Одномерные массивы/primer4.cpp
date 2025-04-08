#include <iostream>
using namespace std;
int main(){
    int n = 5, i = 1;
    int *mas = new int [n];
    int *p;
    p = (mas + n);
    cout << "adress p=" << p << endl;
    while (mas != p){
        *mas = i;
        cout << "mas[" << i - 1 << "]=" << *mas << endl;
        cout << "adress " << mas << endl;
        mas++;
        i++;
    }
    mas = mas - n;
    delete [] mas;
    return 0;
}