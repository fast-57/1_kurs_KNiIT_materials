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
    string str = "5 + (3 + (2 + 4 * (3 - 1) + 2)/4 + 1) * 4";
    int n;
    stack *a = NULL;
    string res = "";
    for (int i = 0; i < str.size(); i++){
        if (str[i] == ' ') continue;
        if (str[i] > '0' && str[i] <= '9'){
            res += str[i];
        }
        else if (str[i] == '('){
            push(a, str[i]);
        }
        else if (str[i] == ')'){
            while (a != NULL && a->inf != '('){
                res += pop(a);
            }
            if (a != NULL) pop(a);
        }
        else{
            int current_prec = (str[i] == '+' || str[i] == '-') ? 1 : 2;
            while (a != NULL && a->inf != '(') {
                int stack_prec = (a->inf == '+' || a->inf == '-') ? 1 : 2;
                if (current_prec > stack_prec) break;
                res += pop(a);
            }
            push(a, str[i]);
    }
}
    while(a != NULL){
        res += pop(a);
    }
    cout << res;
    return 0;

}