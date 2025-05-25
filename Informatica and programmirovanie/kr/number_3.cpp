# include <iostream>
# include <string>
# include <windows.h>
# include <algorithm>
# include <vector>
# include <queue>
# include <cmath>
# include <fstream>
using namespace std;

ifstream in ("input.txt");

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
    return n;
}

void create(tree *&tr, int n){
    int x;
    if (n > 0){
        in >> x;
        tr = node(x);
        int nl = n/2;
        int nr = n - nl - 1;
        create(tr->left, nl);
        create(tr->right, nr);
    }
}

void preorder(tree *tr){
    if (tr){
        cout << tr->inf << " ";
        preorder(tr->left);
        preorder(tr->right);
    }
}

int lefth(tree *tr){
    int k = 0; 
    tree *x = tr;
    while(x){
        k++;
        x = x->left;
    }
    return k - 1;
}

int righth(tree *tr){
    int k = 0;
    tree *x = tr;
    while(x){
        k++;
        x = x->right;
    }
    return k - 1;
}

void add(tree *&tr, int x){
    tree *n = node(x);
    tree *y = tr;
    if (lefth(tr) == righth(tr)){
        do{
            y = y->left;
        }
        while(y->left);
        if (!y->left) y->left = n;
        else y->right = n;
    }
    else{
        do{
            y = y->right;
        }
        while(y->right);
        if (!y->left) y->left = n;
        else y->right = n;
    }
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

void inorder(tree *tr){
    if(tr){
        inorder(tr->left);
        cout << tr->inf << " ";
        inorder(tr->right);
    }
}

void print(tree *tr, int k){
    if(!tr) cout << "Empty tree\n";
    else{
        queue<tree*> cur, next;
        tree *r = tr;
        cur.push(r);
        int j = 0;
        while(cur.size()){
            if (j == 0){
                for(int i = 0; i < (int)pow(2.0, k) - 1; i++)
                    cout << ' ';
            }
            tree *buf = cur.front();
            cur.pop();
            j++;
            if(buf){
                cout << buf->inf;next.push(buf->left);
                next.push(buf->right);
                for(int i = 0; i < (int)pow(2.0, k + 1) - 1; i++)
                    cout << ' ';
            }
            if(!buf){
                for(int i = 0; i < (int)pow(2.0, k + 1) - 1; i++)
                    cout << ' ';
                cout << ' ';
            }
            if(cur.empty()){
                cout << endl;
                swap(cur, next);
            j = 0;
            k --;
            }
        }
    }
}

int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    vector<int> numbers = {5, 9, 2, 8, 3, 4, 1, 0, 7, 6};
    sort(numbers.begin(), numbers.end());
    tree* root = create(numbers, 0, numbers.size() - 1);
    
    // Выводим структуру дерева
    cout << "Структура идеально сбалансированного дерева:" << endl;
    printTree(root);
    cout << endl << endl;
    
    // Выводим результат обратного обхода
    cout << "Результат обратного обхода (postorder):" << endl;
    postorderTraversal(root);
    cout << endl;
    
    return 0;
}