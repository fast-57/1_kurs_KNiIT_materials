# include <iostream>
using namespace std;
struct tree{
    int inf;
    tree *left;
    tree *right;
    tree *parent;
};

struct Tree{
    int inf;
    Tree *right, *left;
    Tree *parent;
    char color;
};

void left_rotate(Tree*& tr, Tree* x){
    Tree* y = x->right;
    x->right = y->left;
    if(y->left){
        y->left->parent = x;
    }
    y->parent = x->parent;
    if(x->parent->left == x)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
    if(!y->parent){
        tr = y;
        y->color = 'b';
    }
}


tree *node(int x){ // создание узла
    tree *n = new tree;
    n->inf = x;
    n->parent = NULL;
    n->right = NULL;
    n->left = NULL;
}

void preorder(tree *tr){ // прямой обход
    if (tr){
        cout << tr->inf;
        preorder(tr->left);
        preorder(tr->right);
    }
}

void postorder(tree *tr){ //  Обратный обход
    if(tr){
        postorder(tr->left);
        postorder(tr->right);
        cout << tr->inf;
    }
}

void inorder(tree *tr){
    if(tr){
        inorder(tr->left);
        cout << tr->inf;
        inorder(tr->right);
    }
}