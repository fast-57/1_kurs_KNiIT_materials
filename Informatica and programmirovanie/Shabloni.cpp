# include <iostream>
using namespace std;
template <typename X>
void create (X **mas, int n)
{
    for(int i = 0; i < n; i++){
        mas[i] = new X[n];
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            mas[i][j] = rand()%10;
        }
    }
}
template <typename X>
void print (X **mas, int n)
{
    for (int i = 0; i < n; i++, cout << "\n"){
        for (int j = 0; j < n; j++){
            cout << mas[i][j] << " \n";
        }
    }
}
int main(){
    int n; cin >> n;
    int **mas = new int*[n];
    create(mas, n);
    print(mas, n);
    float **mas1 = new float*[n];
    create(mas1, n);
    print(mas1, n);
}