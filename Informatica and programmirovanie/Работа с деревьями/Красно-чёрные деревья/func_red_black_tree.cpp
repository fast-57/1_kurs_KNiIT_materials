# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

struct tree{
    int inf;
    string color;
    tree* right;
    tree *left;
    tree *parent;
};

void turn_right(tree* tr, tree* X);
void turn_left(tree* tr, tree* X);
tree* node(tree* p, int X);
void insert(tree*& tr, int X);
tree* Grandparent(tree* X);
tree* Uncle(tree* X);
tree* Sibling(tree* X);
void insert_case1(tree*& tr, tree* X);
void insert_case2(tree*& tr, tree* X);
void insert_case3(tree*& tr, tree* X);
void insert_case4(tree*& tr, tree* X);
void insert_case5(tree*& tr, tree* X);
void insert(tree*& tr, tree*& Prev, int X);
void delete_case1(tree*& tr, tree* X);
void delete_case2(tree*& tr, tree* X);
void delete_case3(tree*& tr, tree* X);
void delete_case4(tree*& tr, tree* X);
void delete_case5(tree*& tr, tree* X);
void delete_case6(tree*& tr, tree* X);
void replace(tree*& tr, tree* X);
void in_order(tree* tr);
int sum_leaves(tree* tr);
void delete_one(tree*& tr, tree* X);

void turn_right(tree* tr, tree* X){
    tree* Y = X->left;
    X->left = Y->right;
    if (Y->right != NULL){
        Y->right->parent = X;
    }
    Y->parent = X->parent;
    if (X == X->parent->left){
        X->parent->left = Y;
    }
    else{
        X->parent->right = Y;
    }
    Y->right = X;
    X->parent = Y;
    if (Y->parent == NULL){
        tr = Y;
        tr->color = "Black";
    }
}

void turn_left(tree* tr, tree* X){
    tree* Y = X->right;
    X->right = Y->left;
    if (Y->left != NULL){
        Y->left->parent = X;
    }
    Y->parent = X->parent;
    if (X == X->parent->left){
        X->parent->left = Y;
    }
    else{
        X->parent->right = Y;
    }
    Y->left = X;
    X->parent = Y;
    if (Y->parent == NULL){
        tr = Y;
        tr->color = "Black";
    }
}

tree *node(tree *p, int X){
    tree *n = new tree;
    n->inf = X;
    n->left = n->right = NULL;
    n->color = "Red";
    n->parent = p;
    return n;
}

void insert(tree *&tr, int X){
    tree *n = node(tr, X);
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
tree* Grandparent(tree* X){
    if (X && X->parent){
        return X->parent->parent;
    }
    else{
        return NULL;
    }
}

tree* Uncle(tree* X){
    tree* g = X->parent->parent;
    if(g == NULL){
        return NULL;
    }
    if (X->parent == g->left){
        return g->right;
    }
    else{
        return g->left;
    }
}

tree* Sibling(tree* X){
    if (X && X->parent){
        if(X->parent->left == X){
            return X->parent->right;
        }
        else{
            return X->parent->left;
        }
    }
    else{
        return NULL;
    }
}

void insert_case1(tree *&tr, tree *X){
    if (X->parent == NULL){
        X->color = "Black";
    }
    else{
        insert_case2(tr, X);
    }
}

void insert_case2(tree *&tr, tree *X){
    if (X->color == "Red"){
        insert_case3(tr, X);
    }
    else{
        return;
    }
}

void insert_case3(tree*& tr, tree *X){
    tree* U = Uncle(X);
    tree* G = Grandparent(X);
    if (U && U->color == "Red" && X->parent->color == "Red"){
        X->parent->color = "Black";
        U->color = "Black";
        G->color = "Red";
        insert_case1(tr, G);
    }
    else{
        insert_case4(tr, X);
    }
}

void insert_case4(tree*& tr, tree* X){
    tree* G = Grandparent(X);
    if (X == X->parent->right && X->parent == Grandparent(X)->left){
        turn_left(tr, X);
        X = X->left;
    }
    else{
        if (X == X->parent->left && X->parent == Grandparent(X)->right){
            turn_right(tr, X);
            X = X->right;
        }
    }
    insert_case5(tr, X);
}

void insert_case5(tree*& tr, tree* X){
    tree* G = Grandparent(X);
    X->parent->color = "Black";
    Grandparent(X)->color = "Red";
    if (X == X->parent->left && X->parent == Grandparent(X)->left){
        turn_right(tr, G);
    }
    else{
        turn_left(tr, G);
    }
}

void insert(tree *&tr, tree *& Prev, int X){
    if (X < Prev->inf && Prev->left == NULL){
        Prev->left = node(Prev, X);
        insert_case1(tr, Prev->left);
    }
    else{
        if (X > Prev->inf && Prev->right == NULL){
            Prev->right = node(Prev, X);
            insert_case1(tr, Prev->right);
        }
        else{
            if (X < Prev->inf && Prev->left){
                insert(tr, Prev->left, X);
            }
            else{
                if (X > Prev->inf && Prev->right){
                    insert(tr, Prev->right, X);
                }
            }
        }
    }
}

void delete_case1(tree*&tr, tree *X){
    if (X->parent == NULL){
        if (X->left){
            X = X->left;
        }
        else{
            X = X->right;
        }
    }
    else{
        delete_case2(tr, X);
    }
}

void delete_case2(tree*&tr, tree *X){
    tree* S = Sibling(X);
    if (S->color == "Red"){
        X->parent->color = "Red";
        S->color = "Black";
        if (X == X->parent->left){
            turn_left(tr, X->parent);
        }
        else{
            turn_right(tr, X->parent);
        }
    }
    delete_case3(tr, X);
}

void delete_case3(tree*&tr, tree *X){
    tree* S = Sibling(X);
    if (X->parent->color == "Black" && S->color == "Black" && (S->left == NULL || S->left->color == "Black") && (S->right == NULL || S->right->color == "Black")){
        S->color = "Red";
        delete_case1(tr, X);
    }
    else{
        delete_case4(tr, X);
    }
}

void delete_case4(tree*& tr, tree *X){
    tree* S = Sibling(X);
    if (X->parent->color == "Red" && S->color == "Black" && (S->left == NULL || S->left->color == "Black") && (S->right == NULL || S->right->color == "Black")){
        S->color = "Red";
        X->parent->color = "Black";
    }
    else{
        delete_case5(tr, X);
    }
}

void delete_case5(tree*& tr, tree *X){
    tree* S = Sibling(X);
    if (S->color == "Black"){
        if (X == X->parent->left && (S->left != NULL && S->left->color == "Red") && (S->right == NULL || S->right->color == "Black")){
            S->color = "Red";
            S->left->color = "Black";
            turn_right(tr, S);
        }
        else{
            if (X == X->parent->right && (S->right != NULL && S->right->color == "Red") && (S->left == NULL || S->left->color == "Black")){
                S->color = "Red";
                S->right->color = "Black";
                turn_left(tr, S);
            }
        }
    }
    delete_case6(tr, X);
}

void delete_case6(tree*& tr, tree* X){
    tree* S = Sibling(X);
    S->color = X->parent->color;
    X->parent->color = "Black";
    if (X == X->parent->left){
        S->right->color = "Black";
        turn_left(tr, X->parent);
    }
    else{
        S->left->color = "Black";
        turn_right(tr, X->parent);
    }
}

void replace(tree *&tr, tree *X){
    if (X->left){
        tree* ch = X->left;
        ch->parent = X->parent;
        if (X->parent){
            if(X == X->parent->left){
                X->parent->left = ch;
            }
            else{
                X->parent->right = ch;
            }
        }
    }
    else{
        tree* ch = X->right;
        ch->parent = X->parent;
        if (X == X->parent->left){
            X->parent->left = ch;
        }
        else{
            X->parent->right = ch;
        }
    }
}

void in_order(tree* tr){
    if (tr){
        in_order(tr->left);
        cout << tr->inf << "(" << tr->color << ") ";
        in_order(tr->right);
    }
}

int sum_leaves(tree* tr){
    if (!tr->left && !tr->right) return tr->inf;
    return sum_leaves(tr->left) + sum_leaves(tr->right);
}

void delete_one(tree*& tr, tree* X){
    tree* ch;
    if (X->right && X->left){
        tree* buf;
        if (X->inf <= tr->inf){
            buf = X->left;
            while (buf->right){
                buf = buf->right;
            }
        }
        else{
            buf = X->right;
            while (buf->left){
                buf = buf->left;
            }
        }
        swap(X->inf, buf->inf);
        X = buf;
    }
    if (X->left || X->right){
        if (X->left && X->right == NULL){
            ch = X->left;
        }
        if (X->right && X->left == NULL){
            ch = X->right;
        }
        replace(tr, X);
        if (X->color == "Black"){
            if (ch->color == "Red"){
                ch->color = "Black";
            }
            else{
                delete_case1(tr, ch);
            }
        }
    }
    else{
        if (X->color == "Black"){
            delete_case1(tr, X);
        }
        if (X->parent){
            if (X == X->parent->left){
                X->parent->left = NULL;
            }
            else{
                X->parent->right = NULL;
            }
        }
    }
    delete X;
}

int main(){
    tree* tr = NULL;
    int elements[] = {10, 5, 15, 3, 7, 12, 18};
    int size = sizeof(elements)/sizeof(elements[0]);

    for(int i = 0; i < size; i++){
        insert(tr, elements[i]);
    }

    in_order(tr);

    cout << "Сумма листьев дерева: " << sum_leaves(tr) << endl;
    return 0;
}