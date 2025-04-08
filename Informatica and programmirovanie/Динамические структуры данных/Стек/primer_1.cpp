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
    string str = "a + (b * (c - (d / 2)))) * 3 - (x + y)";
    int n;
    stack *a = NULL;
    int i = 0;
    while(i < str.length()){
        if (str[i] == '('){
            push(a, str[i]);
        }
        if (str[i] == ')'){
            if (a == NULL){
                cout << "Неправильно, закрывающая скобка встречается раньше открывающей";
                break;
            }
            else{
                pop(a);
            }
        }
        i++;
    }
    if (a == NULL){
        cout << "правильно";
    }
    else{
        cout << "открывающих скобок больше, чем закрывающих";
    }
}
    