# include <iostream>
using namespace std;
struct stack{
    char inf;
    stack *next;
};

void push(stack *&h, char x){
    stack *r = new stack;
    r->inf = x;
    r->next = h;
    h = r;
}

int pop(stack *&h){
    char i = h->inf;
    stack *r = h;
    h = h->next;
    delete r;
    return i;
}

void reverse(stack *&h){
    stack *head1 = NULL;
    while(h)
        push(head1, pop(h));
    h = head1;
}

stack *result(stack *&h){
    stack *res = NULL;
    stack *h1 = NULL;
    while(h){
        int x = pop(h);
        push(res, x);
        while(h){
            int y = pop(h);
            if (x != y) push(h1, y);
        }
        reverse(h1);
        h = h1;
        h1 = NULL;
    }
    reverse(res);
    return res;
}
int main(){
    
}