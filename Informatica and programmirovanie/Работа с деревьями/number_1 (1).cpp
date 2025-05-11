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

tree* find_common_predok(tree* tr, int A, int B){
    if (!tr) return NULL;
    if (tr->inf == A || tr->inf == B) return tr;
    tree* left_predok = find_common_predok(tr->left, A, B);
    tree *right_predok = find_common_predok(tr->right, A, B);

    if(left_predok && right_predok) return tr;
    if (left_predok) return left_predok;
    else return right_predok;
}

bool is_predok(tree* A, tree* B){
    if (!A || !B) return false;
    if (A == B) return true;

    return is_predok(A->left, B) || is_predok(A->right, B);
}

bool find_path(tree* from, tree* to, string& path){
    if(!from) return false;
    if (!path.empty()) path += "->";
    path += to_string(from->inf);
    if (from == to) return true;
    if (find_path(from->left, to, path) || find_path(from->right, to, path)){
        return true;
    }
    path.erase(path.size() - to_string(from->inf).length() - 2);
    return false;
}

void print_path(tree* tr, int A, int B){
    tree* node_A = find(tr, A);
    tree* node_B = find(tr, B);
    if(!node_A || !node_B){
        cout << "Путь от " << A << " до " << B << " не существует\n";
        return;
    }
    if (!is_predok(node_A, node_B)){
        cout << "Путь от " << A << " до " << B << " не существует (A не предок B)\n";
        return;
    }
    string path;
    find_path(node_A, node_B, path);
    cout << "Путь от " << A << " до " << B << ": " << path << endl;
}

int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int n, x, A, B;
    cout << "n = "; cin >> n;
    tree *tr = NULL;
    for(int i = 0; i < n; i++){
        cout << i << ": ";
        cin >> x;
        insert(tr, x);
    }
    cout << "A = "; cin >> A;
    cout << "B = "; cin >> B;
    print_path(tr, A, B);
    return 0;
}