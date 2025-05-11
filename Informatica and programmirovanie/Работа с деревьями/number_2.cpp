# include <iostream>
# include <string>
# include <windows.h>
using namespace std;

struct tree{
    int inf;
    tree* right;
    tree *left;
    tree *parent;
};

tree *node(int x){
    tree *n = new tree;
    n->inf = x;
    n->left = n->right = NULL;
    n->parent = NULL;
    return n;
}

void insert(tree *&tr, int x){
    tree *n = node(x);
    if (!tr) tr = n;
    else{
        tree *y = tr;
        while(y){
            if (n->inf > y->inf)
                if(y->right)
                    y = y->right;
                else{
                    n->parent = y;
                    y->right = n;
                    break;
                }
            else if(n->inf < y->inf)
                if(y->left)
                    y = y->left;
                else{
                    n->parent = y;
                    y->left = n;
                    break;
                }
        }
    }
}

int sum_of_leaves(tree* tr){
    if(!tr) return 0;
    if(!tr->left && !tr->right){
        return tr->inf;
    }
    return sum_of_leaves(tr->left) + sum_of_leaves(tr->right);
}

int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    tree* tr = NULL;
    int n, x;
    cout << "n = "; cin >> n;
    for(int i = 0; i < n; i++){
        cout << i << ": ";
        cin >> x;
        insert(tr, x);
    }

    int sum = sum_of_leaves(tr);
    cout << "Сумма листьев: " << sum << endl;
    return 0;
}