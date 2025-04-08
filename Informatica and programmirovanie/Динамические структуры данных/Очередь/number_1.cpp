# include <iostream>
using namespace std;
struct queue{
    int inf;
    queue *next;
};

void push(queue *&h, queue *&t, int x){
    queue *r = new queue;
    r->inf = x;
    r->next = NULL;
    if (!h && !t){
        h = t = r;
    }
    else{
        t->next = r;
        t = r;
    }
}

int pop(queue *&h, queue *&t){
    queue *r = h;
    int i = h->inf;
    h = h->next;
    if (!h)
        t = NULL;
    delete r;
    return i;
}

void cyclic_sdvig(queue*& h, queue*& t){
    queue* r = h;
    while (r && r->inf % 2 == 0){
        r = r->next;
    }
    queue* new_head = r;
    queue* pred = h;
    while(pred->next != r){
        pred = pred->next;
    }
    pred->next = NULL;
    t->next = h;
    h = new_head;
    t = pred;
}

int main(){
    queue* head = NULL;
    queue* tail = NULL;
    int n, x;
    cout << "n = "; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        push(head, tail, x);
    }

    cyclic_sdvig(head, tail);
    while (head){
        cout << pop(head, tail) << " ";
    }
    return 0;
}