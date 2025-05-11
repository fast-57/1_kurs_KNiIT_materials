# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int main(){
    bool isDirected;
    cout << "Граф ориентированный? 1, если да или 2, если нет"; cin >> isDirected;
    int N, M, n = 10;
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
            sort(Gr[0], Gr[n]);
        Gr[i].erase(unique(Gr[i].begin(), Gr[i].end()));
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < Gr[i].size(); j++){
            cout << Gr[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}