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
            Gr[x].push_back(y);
            Gr[y].push_back(x);
        }
    }
    for(int i = 0; i < N; i++){
        sort(Gr[i].begin(), Gr[i].end());
        Gr[i].erase(unique(Gr[i].begin(), Gr[i].end()), Gr[i].end());
    }
    return Gr;
}

int main(){
    int N, M;
    cout << "Введите количество вершин и рёбер: ";
    cin >> N >> M;

    Gr = create_list_smezh(N, M, false);
    vector<int> stepeni(N);
    for(int i = 0; i < N; i++){
        stepeni[i] = Gr[i].size();
    }

    int v1 = -1, v2 = -1;
    for(int i = 0; i < N; i++){
        if (stepeni[i] % 2 != 0){
            if (v1 == -1){
                v1 = i;
            } else if (v2 == -1){
                v2 = i;
            }
            else{
                cout << "Эйлеров цикл не существует(больше двух вершин с нечётной степенью)";
            }
        }
    }

    if (v1 != -1){
        Gr[v1].push_back(v2);
        Gr[v2].push_back(v1);
        stepeni[v1]++;
        stepeni[v2]++;
    }

    stack<int> st;
    int start_versh = (v1 != -1) ? v1 : 0;
    st.push(start_versh);
    vector<int> res;

    while(!st.empty()){
        int v = st.top();
        st.pop();
        if (stepeni[v] > 0){
            st.push(v);
            int u = Gr[v].back();
            st.push(u);
            Gr[v].pop_back();
            auto it = find(Gr[u].begin(), Gr[u].end(), v);
            if (it != Gr[u].end()) Gr[u].erase(it);
            stepeni[v]--;
            stepeni[u]--;
        }
        else{
            res.push_back(v);
        }
    }

    if (v1 != -1){
        for(int i = 0; i + 1 < res.size(); i++){
            if ((res[i] == v1 && res[i+1] == v2) || (res[i] == v2 && res[i+1] == v1)){
                vector<int> new_res;
                new_res.insert(new_res.end(), res.begin() + i + 1, res.end());
                new_res.insert(new_res.end(), new_res.begin(), res.begin() + i + 1);
                res = new_res;
                break;
            }
        }
    }

    for (int i = 0; i < N; i++){
        if (stepeni[i] != 0){
            cout << "Граф несвязный, Эйлеров цикл несуществует";
            return 0;
        }
    }
    cout << "Эйлеров цикл: ";
    for(int i = 0; i < res.size(); i++){
        cout << res[i];
        if (i != res.size() - 1) cout << " -> ";
    }
    return 0;
}