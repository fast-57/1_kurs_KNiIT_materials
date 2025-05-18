# include <iostream>
# include <vector>
# include <algorithm>
# include <queue>
# include <stack>
using namespace std;

vector<vector<int>> Gr;  
vector<vector<int>> GrT;  
vector<int> used;      
vector<int> order;

vector<vector<int>> create_list_smezh(int N, int M, bool orien){
    vector<vector<int>> Gr(N);
    for(int i = 0; i < M; i++){
        int x, y;
        cin >> x >> y;
        if(orien){
            Gr[x].push_back(y);
        }
        else{
            Gr[y].push_back(x);
        }
    }
    for(int i = 0; i < N; i++){
        sort(Gr[i].begin(), Gr[i].end());
        Gr[i].erase(unique(Gr[i].begin(), Gr[i].end()), Gr[i].end());
    }
    return Gr;
}

void obhod_in_glub_tp_sort(int x){
    used[x] = 1;
    for(int i = 0; i < Gr[x].size(); i++){
        if (!used[Gr[x][i]]){
            obhod_in_glub_tp_sort(Gr[x][i]);
        }
    }
    order.push_back(x);
}



int main(){
    int N, M;
    cout << "Введите количество вершин и рёбер: ";
    cin >> N >> M;

    Gr = create_list_smezh(N, M, true);
    used = vector<int>(N, 0);
    order.clear();

    for(int i = 0; i < N; i++){
        if (!used[i]){
            obhod_in_glub_tp_sort(i);
        }
    }

    reverse(order.begin(), order.end());

    cout << "Топологическая сортировка: ";
    for (int i = 0; i < order.size(); i++){
        cout << order[i] << " ";
    }
    return 0;
}