# include <iostream>
# include <vector>
# include <algorithm>
# include <queue>
using namespace std;

vector<vector<int>> Gr;  
vector<vector<int>> GrT;  
vector<int> used;      
vector<int> path;         
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
            Gr[x].push_back(y);
        }
    }
    for(int i = 0; i < N; i++){
        sort(Gr[i].begin(), Gr[i].end());
        Gr[i].erase(unique(Gr[i].begin(), Gr[i].end()), Gr[i].end());
    }
    return Gr;
}

void obhod_in_glub_obich_graf(vector<vector<int>> Gr, int x){
    used[x] = 1;
    for(int i = 0; i < Gr[x].size(); i++){
        int neighbor = Gr[x][i];
        if(!used[neighbor]){
            obhod_in_glub_obich_graf(Gr, neighbor);
        }
    }
    order.push_back(x);
}

void obhod_in_glub_trans_graf(vector<vector<int>> GrT, int x){
    used[x] = 1;
    path.push_back(x);
    for(int i = 0; i < GrT[x].size(); i++){
        int neighbor = GrT[x][i];
        if(!used[neighbor]){
            obhod_in_glub_trans_graf(GrT, neighbor);
        }
    }
}

void obhod_in_glub(vector<vector<int>> Gr, int x){
    used[x] = 1;
    path.push_back(x);
    for(int i = 0; i < Gr[x].size(); i++){
        int neighbor = Gr[x][i];
        if (Gr[x][i]){
            obhod_in_glub(Gr, neighbor);
        }
    }
}

void dfs1(int x, vector<vector<int>>& Gr, vector<int>& used, vector<int>& order){
    used[x] = 1;
    for(int i = 0; i < Gr[x].size(); i++){
        int neighbor = Gr[x][i];
        if(!used[neighbor]){
            dfs1(neighbor, Gr, used, order);
        }
    }
    order.push_back(x);
}

void dfs2(int x, vector<vector<int>>& Gr, vector<int>& used, vector<int>& order){
    used[x] = 1;
    path.push_back(x);
    for(int i = 0; i < GrT[x].size(); i++){
        int neighbor = GrT[x][i];
        if(!used[neighbor]){
            dfs2(neighbor, Gr, used, order);
        }
    }
}

void find_komponent_sviaz(vector<vector<int>> Gr){
    for(int i = 0; i < Gr.size(); i++){
        if(!used[i]){
            path.clear();
            obhod_in_glub(Gr, i);
            for(int j = 0; j < path.size(); j++){
                cout << path[j] << " ";
            }
            cout << endl;
            
        }
    }
}

void obhod_in_shiriny(vector<vector<int>> Gr, int x){
    queue<int> och;
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

void add_rebr(int A, int B){
    if (find(Gr[A].begin(), Gr[A].end(), B) == Gr[A].end()){
        Gr[A].push_back(B);
    }
}

void print_graph(){
    for(int i = 0; i < Gr.size(); i++){
        cout << "Вершина " << i << ": ";
        for(int j = 0; j < Gr[i].size(); j++){
            cout << Gr[i][j] << " ";
        }
        cout << endl;
    }
}

void polustep_ishoda(){
    for(int i = 0; i < Gr.size(); i++){
        cout << "Вершина " << i << ": полустепень исхода = " << Gr[i].size() << endl;
    }
}

int main(){
    int N, M;
    cout << "Введите количество вершин и рёбер: ";
    cin >> N >> M;

    cout << "Введите ребра(пары вершин A и B): " << endl;
    Gr = create_list_smezh(N, M, true);

    cout << "Полустепени исхода вершин: " << endl;
    polustep_ishoda();
    return 0;
}