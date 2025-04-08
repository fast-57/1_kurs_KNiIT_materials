# include <iostream>
# include <stack>

using namespace std;



void change(stack*& h){
    stack* h1 = nullptr;
    stack* res = nullptr;
    int x, y;
    while (h){
        x = pop(h);
        push(res, x);
        while(h){
            y = pop(h);
            if(x != y){
                push(h1, y);
            }
            reverse(h1);
            h = h1;
            h1 = nullptr;
        }
    }
}
int main(){
    stack* head = nullptr;
    int n = 15, x;
    srand(time(0));
    for(int i = 0; i < n; i++){
        x = rand() % 5;
        cout << x << " ";
        push(head, x);
    }
}