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

char pop(stack *&h){
    char i = h->inf;
    stack *r = h;
    h = h->next;
    delete r;
    return i;
}

int starshinstvo(char op){
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void reverseStack(stack *&str){
    stack *temp = NULL;
    while(str){
        push(temp, pop(str));
    }
    str = temp;
}
void string_to_stack(const string& s, stack*& st){
    for(int i = s.length() - 1; i >= 0; i--){
        if (s[i] != ' '){
            push(st, s[i]);
        }
    }
}

void infix_to_prefix(stack*& input, stack*& output){
    stack* op_stack = NULL;
    stack* temp_result = NULL;
    reverseStack(input);
    char c;
    while (input) {
        char c = pop(input);
        if (isdigit(c)) {
            push(temp_result, c);
        }
        else if (c == ')') {
            push(op_stack, c);
        }
        else if (c == '(') {
            while (op_stack && op_stack->inf != ')') {
                push(temp_result, pop(op_stack));
            }
            if (op_stack) pop(op_stack);
        }
        else {
            while (op_stack && op_stack->inf != ')' && 
                   starshinstvo(op_stack->inf) >= starshinstvo(c)) {
                push(temp_result, pop(op_stack));
            }
            push(op_stack, c);
        }
    }
    
    while (op_stack) {
        push(temp_result, pop(op_stack));
    }
    reverseStack(temp_result);
    
    
    while (temp_result) {
        push(output, pop(temp_result));
    }
}

int main(){
    string str = "5 + (3 + (2 + 4 * (3 - 1) + 2)/4 + 1) * 4";
    stack* input = NULL;
    string_to_stack(str, input);
    stack* output = NULL;
    infix_to_prefix(input, output);
    while(output){
        cout << pop(output) << " ";
    }
    return 0;
}