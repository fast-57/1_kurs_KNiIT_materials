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

void remove_max(queue*& h, queue*& t){
    int max_val = h->inf;
    queue* pred = h->next;
    while(pred){
        if (pred->inf > max_val)
            max_val = pred->inf;
        pred = pred->next;
    }
    queue* temp_h = NULL;
    queue* temp_t = NULL;
    bool first_removed = false;
    while(h){
        int x = pop(h, t);
        if (!first_removed && x == max_val){
            first_removed = true;
        }
        else{
            push(temp_h, temp_t, x);
        }
    }
    h = temp_h;
    t = temp_t;
    temp_h = temp_t = NULL;
    int last_max_pos;
    int pos = 0;
    pred = h;
    while (pred){
        if (pred->inf == max_val)
            last_max_pos = pos;
        pos++;
        pred = pred->next;
    }
    pos = 0;
    while(h){
        int x = pop(h, t);
        if (pos != last_max_pos){
            push(temp_h, temp_t, x);
        }
        pos++;
    }
    h = temp_h;
    t = temp_t;
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

    remove_max(head, tail);
    while (head){
        cout << pop(head, tail) << " ";
    }
    return 0;
}