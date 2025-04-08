# include <iostream>
using namespace std;

struct stack{
    int inf;
    stack *next;
};

void push(stack *&h, int x){
    stack *r = new stack;
    r->inf = x;
    r->next = h;
    h = r;
}
int pop(stack *&h){
    int i = h->inf;
    stack *r = h;
    h = h->next;
    delete r;
    return i;
}
stack* reverseStack(stack* h){
    stack* reversed = NULL;
    while(h){
        push(reversed, pop(h));
    }
    return reversed;
}

stack* razdelenie_chisel(stack*& h){
    stack* save_poryadok = NULL;
    stack* nechet = NULL;
    stack* chet = NULL;
    stack* temp = reverseStack(h);

    while(temp){
        int x = pop(temp);
        if (x % 2 != 0){
            push(nechet, x);
        }
        else{
            push(chet, x);
        }
    }
    nechet = reverseStack(nechet);
    chet = reverseStack(chet);
    while(nechet){
        push(save_poryadok, pop(nechet));
    }
    while(chet){
        push(save_poryadok, pop(chet));
    }
    return reverseStack(save_poryadok);
}
int main(){
    int n;
    cout << "n = ";
    cin >> n;
    stack *head = NULL;
    int x;
    for(int i = 0; i < n; i++){
        cin >> x;
        push(head, x);
    }
    stack* new_stack = razdelenie_chisel(head);
    while(new_stack){
        cout << pop(new_stack) << " ";
    }
    return 0;

}