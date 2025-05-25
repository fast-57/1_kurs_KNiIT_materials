# include <iostream>
# include <vector>
# include <list>
using namespace std;
int M;
vector<int> A;

void create_hesh_table(vector<int>A, vector<list<int>>& hashTable, int M){
    hashTable = vector<list<int>>(M);
    for (int i = 0; i < A.size(); i++){
        int k = A[i] % M;
        hashTable[k].push_back(A[i]);
    }
}

list<int>::iterator find_el_heshTable(vector<list<int>>& A, int X){
    int M = A.size();
    int k = X % M;
    for(auto it = A[k].begin(); it != A[k].end(); it++){
        if (*it == X){
            return it;
        }
    }
    return A[k].end();
}

bool delete_el_hashtable(vector<list<int>>& A, int X){
    int M = A.size();
    int k = X % M;
    for(auto it = A[k].begin(); it != A[k].end();){
        if (*it == X){
            A[k].erase(it);
            return true;
        }
    }
    return false;
}