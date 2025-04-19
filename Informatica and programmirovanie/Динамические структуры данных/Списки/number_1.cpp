# include <iostream>
using namespace std;
struct list{
    int inf;
    list *next;
    list *prev;
};

void push(list *&h, list*&t, int x){
    list *r = new list;
    r->inf = x;
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

void print(list *h, list *t){
    list *p = h;
    while(p){
        cout << p->inf << " ";
        p = p->next;
    }
}

list *find(list *h, list *t, int x){
    list *p = h;
    while(p){
        if (p->inf == x) break;
        p = p->next;
    }
    return p;
}

void insert_after(list *&h, list *&t, list *r, int y){
    list *p = new list;
    p->inf = y;
    if(r == t){
        p->next = NULL;
        p->prev = r;
        r->next = p;
        t = p;
    }
    else{
        r->next->prev = p;
        p->next = r->next;
        p->prev = r;
        r->next = p;
    }
}

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
        h->prev = NULL;
        delete p;
    }
}

int find_max(list*& h, list*& t){
    int max_val = h->inf;
    list* temp_h = NULL;
    list* temp_t = NULL;
    list *current = h;
    while(current){
        int x = current->inf;
        if (x > max_val) max_val = x;
        push(temp_h, temp_t, x);
        current = current->next;
    }

    h = NULL;
    t = NULL;
    current = temp_h;
    while (current){
        int x = current->inf;
        push(h, t, x);
        current = current->next;
    }
    return max_val;
}

void ydalenie_first_and_last_max_el(list *&h, list *&t){
    int max_val = find_max(h, t);
    int first_pos = -1;
    int last_pos;
    int pos = 0;
    list* temp_h = NULL;
    list* temp_t = NULL;
    list* current = h;
    while(current){
        if(current->inf == max_val){
            if (first_pos == -1) first_pos = pos;
            last_pos = pos;
        }
        pos++;
        current = current->next;
    }
    list *new_h = NULL;
    list *new_t = NULL;
    current = h;
    pos = 0;
    while(current){
        if (!(current->inf == max_val && (pos == first_pos || pos == last_pos))){
            push(new_h, new_t, current->inf);
        }
        pos++;
        current = current->next;
    }
    h = new_h;
    t = new_t;
}

int main(){
    list *h = NULL;
    list *t = NULL;
    int x;
    int n = 12;
    for (int i = 0; i < n; i++){
        cin >> x;
        push(h, t, x);
    }
    ydalenie_first_and_last_max_el(h, t);
    print(h, t);
    return 0;

}