// удаление
# include <iostream>
using namespace std;
int main(){
    int n, m; cin >> n;
    srand(time(NULL));
    int* mas = new int[n];
    for (int i{0}; i < n; i++){
        mas[i] = rand()%10;
        cout << mas[i] << " ";
    }
    cout << "\n";
    int a, b; cin >> a >> b;
    if (b < a){
        swap(a, b);
    }
    for(int i{0}; i < n;){
        if(mas[i] > a && mas[i] < b){
            for(int j{i}; j < n - 1; j++){
                mas[j] = mas[j + 1];
            n--;
        }
    }
    
        else i++;
    }
    for (int i{0}; i < n; i++){
        cout << mas[i] << " ";
    }


}

// вставка
// # include <iostream>
// using namespace std;
// int main(){
//     int n, m; cin >> n;
//     srand(time(NULL));
//     int* mas = new int[n];
//     for (int i{0}; i < n; i++){
//         mas[i] = rand()%10;
//         cout << mas[i] << " ";
//     }
//     cout << "\n";
//     int a, b; cin >> a >> b;
//     if (b < a){
//         swap(a, b);
//     }
//     for(int i{0}; i < n; i++){
//         if(mas[i] > a && mas[i] < b){
//             for(int j{n}; j > i; j--){
//                 mas[j] = mas[j - 1];
//             n++;
//             mas[i] = 0;
//             i++;
//         }
//     }
    
//         else i++;
//     }
//     for (int i{0}; i < n; i++){
//         cout << mas[i] << " ";
//     }


// }