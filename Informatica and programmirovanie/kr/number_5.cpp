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
vector<int> pr;
vector<vector<int>> cycles;
vector<vector<int>> cycles_sort;

vector<int> obhod_in_shiriny(const vector<vector<int>>& Gr, int start) {
    vector<int> path;
    if(start < 0 || start >= Gr.size()) return path; // Проверка на корректность вершины
    
    vector<bool> used(Gr.size(), false);
    queue<int> och;
    
    och.push(start);
    used[start] = true;
    
    while(!och.empty()) {
        int y = och.front();
        och.pop();
        path.push_back(y);
        
        for(int i = 0; i < Gr[y].size(); i++) {
            int neighbor = Gr[y][i];
            if(!used[neighbor]) {
                used[neighbor] = true;
                och.push(neighbor);
            }
        }
    }
    return path;
}


void print_graph(vector<vector<int>>Gr){
    for(int i = 0; i < Gr.size(); i++){
        cout << "Вершина " << i << ": ";
        for(int j = 0; j < Gr[i].size(); j++){
            cout << Gr[i][j] << " ";
        }
        cout << endl;
    }
}


int main(){
    Gr = {{1, 2}, {}, {}, {1}, {3}};
    print_graph(Gr);
    int start_versh;
    cout << "Введите стартовую вершину для обхода: ";
    cin >> start_versh;
    vector<int> obhod = obhod_in_shiriny(Gr, start_versh);
    cout << "Порядок обхода в ширину: ";
    for(int i = 0; i < obhod.size(); i++){
        cout << obhod[i] << " ";
    }
    return 0;
}