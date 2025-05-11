# include <iostream>
# include <vector>
# include <algorithm>
# include <queue>
using namespace std;

void obhod_in_glub(vector<vector<int>> Gr, int x){
    vector<int> used;
    vector<int> path;
    used[x] = 1;
    path.push_back(x);
    for(int i = 0; i < Gr[x].size(); i++){
        int neighbor = Gr[x][i];
        if (Gr[x][i]){
            obhod_in_glub(Gr, neighbor);
        }
    }
}

void obhod_in_shiriny(vector<vector<int>> Gr, int x){
    queue<int> och;
    vector<int> used;
    vector<int> path;
    used[x] = 1;
    path.push_back(x);
    while(!och.empty()){
        int y = och.front();
        och.pop();
        for(int i = 0; i < Gr[y].size(); i++){
            if(Gr[y][i]){
                Gr[y][i] = 1;
                path.push_back(Gr[y][i]);
                och.push(Gr[y][i]);
            }
        }
    }
}

int main(){
    bool isDirected;
    cout << "Граф ориентированный? 1, если да или 2, если нет"; cin >> isDirected;
    int N, M;
    cout << "Введите количество вершин: "; cin >> N;
    cout << "Введите количество рёбер: "; cin >> M;
    vector<vector<int>> Gr;
    Gr.resize(N);
    for(int i = 0; i < M; i++){
        int x, y;
        cin >> x >> y;
        if(isDirected){
            if (x > N || y > N){
                continue;
            }
            else{
                Gr[x].push_back(y);
            }
        }
        else{
            if(x > N || y > N){
                Gr[x].push_back(y);
                Gr[x].push_back(x);
            }
        }
        for(int i = 0; i < N; i++){
            sort(Gr[i].begin(), Gr[i].end());
        Gr[i].erase(unique(Gr[i].begin(), Gr[i].end()), Gr[i].end());
        }
    }
    for(int i = 0; i < N; i++){
        cout << i << ": ";
        for(int j = 0; j < Gr[i].size(); j++){
            cout << Gr[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}