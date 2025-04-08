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

int count_del(int n){
    if (n == 1) return 1;
    int count = 2;
    for(int i = 2; i*i <= n; i++){
        if (n % i == 0){
            if (i * i == n) count++;
            else count += 2;
        }
    }
    return count;
}

int find_max_del(stack* h){
    int max_count = 0;
    while (h){
        int b = count_del(h->inf);
        if (b > max_count) max_count = b;
        h = h->next;
    }
    return max_count;
}
stack* remove_max_del(stack*& h){
    int max_count = find_max_del(h);
    stack* temp = NULL;
    stack* result = NULL;
    reverse(h);
    while (h){
        int x = pop(h);
        if (count_del(x) != max_count){
            push(temp, x);
        }
    }
    while(temp){
        push(result, pop(temp));
    }
    return result;
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
    stack* new_stack = remove_max_del(head);
    while(new_stack){
        cout << pop(new_stack) << " ";
    }
    return 0;

}