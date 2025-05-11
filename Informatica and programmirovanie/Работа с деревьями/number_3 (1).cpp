# include <iostream>
# include <string>
# include <windows.h>
# include <algorithm>
# include <vector>
# include <queue>
# include <cmath>
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

void inorder(tree *tr){
    if(tr){
        inorder(tr->left);
        cout << tr->inf << " ";
        inorder(tr->right);
    }
}

tree *find(tree *tr, int x){
    if(!tr || x == tr->inf)
        return tr;
    if(x < tr->inf)
        return find(tr->left, x);
    else
        return find(tr->right, x);
}

tree *Min(tree *tr){
    if (!tr->left) return tr;
    else return Min(tr->left);
}

tree *Max(tree *tr){
    if (!tr->right) return tr;
    else return Max(tr->right);
}

tree *Next(tree*tr, int x){
    tree *n = find(tr, x);
    if (n->right)
        return Min(n->right);
    tree *y = n->parent;
    while(y && n == y->right){
        n = y;
        y = y->parent;
    }
    return y;
}

tree *Prev(tree*tr, int x){
    tree *n = find(tr, x);
    if (n->left)
        return Max(n->left);
    tree *y = n->parent;
    while(y && n == y->left){
        n = y;
        y = y->parent;
    }
    return y;
}


void Delete(tree *&tr, tree *v){
    tree *p = v->parent;
    if(!p) tr = NULL;
    else if(!v->left && !v->right){
        if(p->left == v)
            p->left = NULL;
        if(p->right == v)
            p->right = NULL;
        delete v;
    }
    else if(!v->left || !v->right){
        if(!p){
            if(!v->left){
                tr = v->right;
                v->parent = NULL;
        }
        else{
            tr = v->left;
            v->parent = NULL;
        }
    }
    else{
        if(!v->left){
            if(p->left == v)
                p->left = v->right;
            else
                p->right = v->right;
        v->right->parent = p;
        }
        else{
            if(p->left == v)
                p->left = v->left;
            else
                p->right = v->left;
            v->left->parent = p;
            }
            delete v;
        }
    }
    else{
        tree *succ = Next(tr, v->inf);
        v->inf = succ->inf;
        if(succ->parent->left == succ){
            succ->right->parent = succ->parent;
        }
        else{
            succ->parent->right = succ->right;
            if(succ->right)
                succ->right->parent == succ->parent;
        }
        delete succ;
    }
}

void collect_leaves(tree* tr, vector<int>& leaves){
    if(!tr) return;
    if(!tr->left && !tr->right){
        leaves.push_back(tr->inf);
    }
    collect_leaves(tr->left, leaves);
    collect_leaves(tr->right, leaves);
}

tree* find_grandparent(tree *tr){
    if (!tr || !tr->parent) return NULL;
    return tr->parent->parent;
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
    tree* tr = NULL;
    int n, x;
    cout << "n = "; cin >> n;
    for(int i = 0; i < n; i++){
        cout << i << ": ";
        cin >> x;
        insert(tr, x);
    }
    int k = int(log((float)n) / log((float)2.0));
    vector<int> leaves;
    collect_leaves(tr, leaves);
    sort(leaves.begin(), leaves.end());
    int sredn_leaf = leaves[leaves.size() / 2];
    tree* leaf_tr = find(tr, sredn_leaf);
    if(leaf_tr){
        tree* grandparent = find_grandparent(leaf_tr);
        if(grandparent){
            cout << "Удаляем деда (" << grandparent->inf << ") листа " << sredn_leaf << endl;
            Delete(tr, grandparent);
        }
        else{
            cout << "У листа " << sredn_leaf << "нет деда" << endl;
        }
    }
    print(tr, k);
    return 0;
}