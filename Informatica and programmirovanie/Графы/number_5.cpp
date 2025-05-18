# include <iostream>
# include <vector>
# include <algorithm>
# include <queue>
# include <stack>
using namespace std;

vector<vector<int>> Gr;  
vector<vector<int>> GrT;  
vector<int> used;      
vector<int> path;         
vector<int> order;
vector<int> pr;
vector<vector<int>> cycles;
vector<vector<int>> cycles_sort;
vector<int> in_versh;

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

void find_Eileroth_cycle_neorien(vector<int> stepen_vershini){
    int N = Gr.size();
    vector<int> res;
    stack<int> st;
    int v1 = -1, v2 = -1;
    for(int i = 0; i < N; i++){
        if (stepen_vershini[i] % 2 != 0){
            if (v1 == -1){
                v1 = i;
            }
            else if (v2 == -1){
                v2 = i;
            }
            else{
                cout << "Цикла нет";
            }
        }
    }
    if (v1 != -1){
        Gr[v1].push_back(v2);
        Gr[v2].push_back(v1);
        stepen_vershini[v1]++;
        stepen_vershini[v2]++;
    }
    st.push(v1);
    while(!st.empty()){
        int v = st.top();
        if (stepen_vershini[v] != 0){
            int u = Gr[v].back();
            st.push(u);
            Gr[v].pop_back();
            Gr[u].erase(find(Gr[u].begin(), Gr[u].end(), v));
            stepen_vershini[v]--;
            stepen_vershini[u]--;
        }
        else{
            res.push_back(v);
            st.pop();
        }
    }
    if (v1 != -1){
        for (int i = 0; i + 1 < res.size(); i++){
            if ((res[i] == v1 && res[i+1] == v2) || (res[i] == v1 && res[i+1] == v2)){
                vector<int> new_res;
                new_res.insert(new_res.end(), res.begin() + i + 1, res.end());
                new_res.insert(new_res.end(), res.begin(), res.begin() + i + 1);
                res = new_res;
                break;
            }
        }
    }
    for(int i = 0; i < N; i++){
        if (stepen_vershini[i] != 0){
            cout << "граф несвязный, значит Эйлерова цикла нет";
            return;
        }
    }
    cout << "Эйлеров цикл: ";
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;
}

int main(){
    int N, M;
    cout << "Введите количество вершин и рёбер"

    return 0;
}