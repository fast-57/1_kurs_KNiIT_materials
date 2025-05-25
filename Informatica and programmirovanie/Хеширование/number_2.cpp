#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;
struct rabotnick{
    string familia;
    string post;
    int birthDay, birthMonth, birthYear;
    int opit;
    double zarplata;
};

int INF = -1;

int hash_function_1(int birthYear, int M){
    return birthYear % M;
}

int Hash_function2(int opit, int M){
    double A = (sqrt(5)-1)/2;
    double temp = opit * A;
    temp = temp - (int)temp;
    return 1 + (int)((M - 1) * temp);
}

void create_hash_table(vector<rabotnick>& rabotnicki, int M, vector<rabotnick>& hashtable){
    hashtable = vector<rabotnick>(M);
    for(int i = 0; i < M; i++){
        hashtable[i].birthYear = INF;
    }
    for (int i = 0; i < rabotnicki.size(); i++){
        int k = hash_function_1(rabotnicki[i].birthYear, M);
        int second = Hash_function2(rabotnicki[i].opit, M);
        bool inserted = false;
        for (int j = 0; j < M; j++){
            int p = (k + j * second) % M;
            if (hashtable[p].birthYear == INF){
                hashtable[p] = rabotnicki[i];
                inserted = true;
                break;
            }
        }
    }
}

bool find_rabotnick(vector<rabotnick>& hashtable, int birthYear, int opit, int M, rabotnick& result){
    int k = hash_function_1(birthYear, M);
    int second = Hash_function2(opit, M);
    for(int i = 0; i < M; i++){
        int p = (k + i * second) % M;
        if (hashtable[p].birthYear == INF){
            return false;
        }
        if (hashtable[p].birthYear == birthYear && hashtable[p].opit == opit){
            result = hashtable[p];
            return true;
        }
    }
    return false;
}


void print_hash_table(vector<rabotnick>& hashtable){
    for(int i = 0; i < hashtable.size(); i++){
        cout << "Ячейка " << i << ": ";
        if (hashtable[i].birthYear == INF){
            cout << "пусто";
        }
        else{
            cout << hashtable[i].familia << " (" << hashtable[i].birthYear << ", стаж: " << hashtable[i].opit << ")";
        }
        cout << endl;
    }
}

int main(){
    vector<rabotnick> rabotniki;
    string inputFilename = "data.txt";
    ifstream inputFile(inputFilename);

    rabotnick emp;
    while (inputFile >> emp.familia >> emp.post >> emp.birthDay >> emp.birthMonth >> emp.birthYear >> emp.opit >> emp.zarplata) {
        rabotniki.push_back(emp);
    }
    inputFile.close();

    int M;
    cout << "Введите размер хеш-таблицы M: ";
    cin >> M;

    vector<rabotnick> hashtable;
    create_hash_table(rabotniki, M, hashtable);
    cout << "\nХеш-таблица:\n";
    print_hash_table(hashtable);
    int searchYear, searchOpit;
    cout << "\nВведите год рождения и стаж для поиска: ";
    cin >> searchYear >> searchOpit;
    rabotnick found;
    if (find_rabotnick(hashtable, searchYear, searchOpit, M, found)){
        cout << "Найден: " << found.familia << ", " << found.post << ", зарплата: " << found.zarplata << endl;
    }
    else{
        cout << "Работник не найден.\n";
    }
        return 0;
}