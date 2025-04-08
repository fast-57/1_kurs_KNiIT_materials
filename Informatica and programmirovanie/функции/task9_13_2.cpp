# include <iostream>
# include <windows.h>
using namespace std;

template <typename X>
X **create(X c, int n, int m){
    X **a = new X *[n];
    for (int i = 0; i < n; i++)
        a[i] = new X[m];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }
    return a;
}

template <typename X>
void print(X **a, int n, int m){
    for (int i = 0; i < n; i++, cout << endl)
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
}

template<typename X>
X **change(X **a, int n, int m){
    int M = 0;
    for (int i = 0; i < n; i++){
        int sum = 0;
        for (int j = 0; j < m; j++){
            sum += int(a[i][j]);
        }
        if (sum > M){
            M = i;
        }
        cout << sum;
    }
    swap(a[0], a[M]);
    return a;
}

int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int n, m;
    cout << "Input dimension\n";
    cin >> n >> m;
    char c;
    do{
        cout << "Введите тип:\n1 - int\n2 - double\n3 - char\n4 - float\n";
        int k;
        cin >> k;
        switch(k){
            case 1:
            {
                int c = 1;
                int **a = create(c, n, m);
                cout << "INT:\n";
                print(a, n, m);
                a = change(a, n, m);
                cout << "New:\n";
                print(a, n, m);
                break;
            }
            case 2:{
                double c1 = 1;
                double **a1 = create(c1, n, m);
                cout << "DOUBLE:\n";
                print(a1, n, m);
                a1 = change(a1, n, m);
                cout << "New:\n";
                print(a1, n, m);
                break;
            }
            case 3:{
                char c2 = '1';
                char **a2 = create(c2, n, m);
                cout << "CHAR:\n";
                print(a2, n, m);
                a2 = change(a2, n, m);
                cout << "New:\n:";
                print(a2, n, m);
                break;
            }
            case 4:{
                float c3 = 1;
                float **a3 = create(c3, n, m);
                cout << "FLOAT:\n";
                print(a3, n, m);
                a3 = change(a3, n, m);
                cout << "New:\n";
                print(a3, n, m);
                break;
            }
            default: cout << "Неправильно введены данные\n";
        }
        cout << "Ещё раз? Y - да, N - нет\n";
        cin >> c;
    }
    while (c != 'N');
    return 0;
}
