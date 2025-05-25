#include <iostream>
#include <vector>
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

struct list{
    rabotnick data;
    list *next;
    list *prev;
};


void push(list *&h, list*&t, rabotnick &x){
    list *r = new list;
    r->data = x;
    r->next = NULL;
    if (!h && !t){
        r->prev = NULL;
        h = r;
    }
    else{
        t->next = r;
        r->prev = t;
    }
    t = r;
}

void print(list *h){
    list *p = h;
    while(p){
        cout << p->data.familia << " (" << p->data.birthYear << ") -> ";
        p = p->next;
    }
    cout << "NULL\n";
}

list *find(list *h, list *t, int birthYear){
    list *p = h;
    while(p){
        if (p->data.birthYear == birthYear) break;
        p = p->next;
    }
    return p;
}

list *heads = NULL;
list *tails = NULL;

void del_node(list *&h, list *&t, list *r){
    if(r == h && r == t)
        h = t = NULL;
    else if (r == h){
        h = h->next;
        h->prev = NULL;
    }
    else if(r == t){
        t = t->prev;
        t->next = NULL;
    }
    else{
        r->next->prev = r->prev;
        r->prev->next = r->next;
    }
    delete r;
}

void del_list(list *&h, list *&t){
    while(h){
        list *p = h;
        h = h->next;
        delete p;
    }
    t = NULL;
}

int Hash_function(int birthYear, int M){
    double A = (sqrt(5)-1)/2;
    double temp = birthYear * A;
    temp = temp - (int)temp;
    return (int)(M*temp);
}

void Create_hash_table(vector<rabotnick>& rabotnicki, list** Hash_table, int M){
    for(int i = 0; i < M; i++){
        Hash_table[i] = NULL;
    }
    for(int i = 0; i < rabotnicki.size(); i++){
        int k = Hash_function(rabotnicki[i].birthYear, M);
        list* head = Hash_table[k];
        list* tail = NULL;
        if (head){
            tail = head;
            while (tail->next) tail = tail->next;
        }
        push(head, tail, rabotnicki[i]);
        Hash_table[k] = head;
    }
}

void print_hash_table(list** Hash_table, int M){
    for(int i = 0; i < M; i++){
        cout << "Ячейка " << i << ": ";
        print(Hash_table[i]);
    }
}

void search_by_year(list** Hash_table, int M, int year){
    int k = Hash_function(year, M);
    list* p = Hash_table[k];
    bool found = false;
    cout << "Результаты поиска по году " << year << ":\n";
    while(p){
        if (p->data.birthYear == year){
            cout << p->data.familia << ", " << p->data.post << ", " << p->data.birthDay << "."  << p->data.birthMonth << "." << p->data.birthYear << ", "
                 << "опыт: " << p->data.opit << ", зарплата: " << p->data.zarplata << endl;
            found = true;
        }
        p = p->next;
    }
}

void delete_by_year(list** Hash_table, int M, int year){
    int k = Hash_function(year, M);
    list* head = Hash_table[k];
    list* tail = NULL;
    if (head){
        tail = head;
        while(tail->next) tail = tail->next;
    }
    bool deleted = false;
    list *p = head;
    while(p){
        if (p->data.birthYear == year){
            list* temp = p->next;
            del_node(head, tail, p);
            p = temp;
            deleted = true;
        }
        else{
            p = p->next;
        }
    }
    Hash_table[k] = head;
    if (deleted){
        cout << "Работники с годом рождения " << year << " удалены.\n";
    }
    else{
        cout << "Работники с годом рождения " << year << " не найдены.\n";
    }
}

int main() {
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

    list** hashtable = new list*[M];
    Create_hash_table(rabotniki, hashtable, M);
    
    cout << "\nХеш-таблица:\n";
    print_hash_table(hashtable, M);
    
    int searchYear;
    cout << "\nВведите год рождения для поиска: ";
    cin >> searchYear;
    search_by_year(hashtable, M, searchYear);
    
    int deleteYear;
    cout << "\nВведите год рождения для удаления: ";
    cin >> deleteYear;
    delete_by_year(hashtable, M, deleteYear);
    
    cout << "\nОбновленная хеш-таблица:\n";
    print_hash_table(hashtable, M);
    
    return 0;
}