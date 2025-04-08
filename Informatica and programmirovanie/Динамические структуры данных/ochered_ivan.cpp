# include <iostream>
# include <stack>
# include <vector>
# include <algorithm>
# include <time.h>
using namespace std;
template<typename type>
struct Node{
    type inf;
    Node* next;
    Node(type value) : inf(value), next(nullptr){}
};

template<typename type>
class Queue{
private:
    Node<type>* head;
    Node<type>* tail;
public:
    Queue() : head(nullptr), tail(nullptr) {}
    void push(type value);
    type pop();
    bool empty(){
        return !head;
    }
};


int main(){
    Queue<int> a;
    int n = 15, x;
    srand(time(0));
    for (int i = 0; i < n; i++){
        x = rand() % 5;
        cout << x << " ";
        a.push(x);
    }

    cout << "\n";
    Queue<int>res = change(a);
    while(!res.empty())
        cout << res.pop() << " ";
    return 0;
}