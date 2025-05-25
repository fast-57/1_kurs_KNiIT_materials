#include <iostream>
using namespace std;

struct list {
    int inf;
    list* next;
    list* prev;
};

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

void push(list*& h, list*& t, int x) {
    list* r = new list;
    r->inf = x;
    r->next = NULL;
    if (!h && !t) {
        r->prev = NULL;
        h = r;
    }
    else {
        t->next = r;
        r->prev = t;
    }
    t = r;
}

void print(list* h) {
    list* p = h;
    while (p) {
        cout << p->inf << " ";
        p = p->next;
    }
    cout << endl;
}

void insert_after(list*& h, list*& t, list* r, int y) {
    list* p = new list;
    p->inf = y;
    if (r == t) {
        p->next = NULL;
        p->prev = r;
        r->next = p;
        t = p;
    }
    else {
        r->next->prev = p;
        p->next = r->next;
        p->prev = r;
        r->next = p;
    }
}

void del_node(list*& h, list*& t, list* r) {
    if (r == h && r == t) {
        h = t = NULL;
    }
    else if (r == h) {
        h = h->next;
        h->prev = NULL;
    }
    else if (r == t) {
        t = t->prev;
        t->next = NULL;
    }
    else {
        r->next->prev = r->prev;
        r->prev->next = r->next;
    }
    delete r;
}

void del_sostav_el(list*& h, list*& t, int newElement) {
    list* current = h;
    while (current) {
        list* nextNode = current->next;
        if (!isPrime(current->inf)) {
            del_node(h, t, current); 
        }
        else {
            insert_after(h, t, current, newElement);
            current = current->next;
        }
        current = nextNode;
    }
}

int main() {
    list* h = NULL;
    list* t = NULL;
    int x;
    int n;

    cout << "Введите количество элементов списка: ";
    cin >> n;
    cout << "Введите элементы списка: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        push(h, t, x);
    }

    int newElement = 0;
    del_sostav_el(h, t, newElement);

    cout << "Результат: ";
    print(h);

    return 0;
}