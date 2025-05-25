# include <iostream>
# include <vector>
# include <algorithm>
# include <queue>
using namespace std;

vector<vector<int>> Gr;
vector<vector<int>> Gr_ves;
vector<int> dist;  
vector<int> used;      
vector<int> parent;
int N;

void init(int n){
    N = n;
    Gr = vector<vector<int>>(n);
    Gr_ves = vector<vector<int>>(n);
    dist = vector<int>(n, INT_MAX);
    parent = vector<int>(n, -1);
    used = vector<int>(n, 0);
}

void alg(int start){
    dist[start] = 0;
    for(int i = 0; i < N; i++){
        int u = -1;
        for(int j = 0; j < N; j++){
            if (!used[j] && (u == -1 || dist[j] < dist[u])){
                u = i;
            }
        }
        if (u == -1) break;
        used[u] = 1;
        for(int j = 0; j < Gr[u].size(); j++){
            int v = Gr[u][j];
            int w = Gr_ves[u][j];
            if (dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }
}

void print_path(int start, int end){
    if (dist[end] == INT_MAX){
        cout << "нет пути";
        return;
    }
    vector<int> path;
    for(int v = end; v != start; v = parent[v]){
        path.push_back(v);
    }
    path.push_back(start);
    for(int i = path.size() - 1; i >= 0; i--){
        cout << path[i];
        if (i != 0) cout << " -> ";
    }
}

int main(){
    int M, start;
    cout << "Введите количество вершин и рёбер: ";
    cin >> N >> M;
    Gr = vector<vector<int>>(N);
    Gr_ves = vector<vector<int>>(N);
    dist = vector<int>(N, INT_MAX);
    parent = vector<int>(N, -1);
    used = vector<int>(N, 0);
    cout << "Введите рёбра (пары вершин и вес):\n";
    for(int i = 0; i < M; i++){
        int x, y, w;
        cin >> x >> y >> w;
        Gr[x].push_back(y);
        Gr_ves[x].push_back(w);
        Gr[y].push_back(x);
        Gr_ves[y].push_back(w);
    }
    cout << "Введите стартовую вершину: ";
    cin >> start;
    alg(start);
    cout << "\nКрадчайшие пути от вершины " << start << ":\n";
    for(int i = 0; i < N; i++){
        if (i == start) continue;
        cout << "До вершины " << i << ": ";
        if (dist[i] == INT_MAX){
            cout << "нет пути";
        }
        else{
            cout << "расстояние = " << dist[i] << ", путь: ";
            print_path(start, i);
        }
        cout << endl;
    }

    return 0;
}