# include <iostream>
# include <vector>
# include <list>
using namespace std;
int M;
vector<int> A;
int INF;

void create_hash_table(vector<int> A, int M, vector<int>& hash){
    hash = vector<int>(M, INF);
    for(int i = 0; i < A.size(); i++){
        int k = A[i] % M;
        int j = 0;
        bool inserted = false;
        while (!inserted){
            int p = (k + j) % M;
            if (hash[p] == INF){
                hash[p] = A[i];
                inserted = true;
            }
            else{
                j++;
            }
        }
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