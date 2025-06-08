#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int const mod = 1e9 + 7;

#define anhduck "Mai Anh Duc"

#define endl "\n"
#define ii pair<int,int>
#define iii pair<pair<int,int>>
// Bài này có thể code theo thuật toán Tarjan nhưng lười =))
int n, m;
vector <int> adj[10005];
bool visited[10005];
void input(){
    memset(visited, false, sizeof(visited));
    cin >> n >> m;
    for(int i = 0; i <= n; i++){
        adj[i].clear();
    }
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}
void DFS(int u){
    visited[u] = true;
    for(auto v : adj[u]){
        if(!visited[v]){
            DFS(v);
        }
    }
}
int tplt(){
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            ++cnt;
            DFS(i);
        }
    }
    return cnt;
}
void solution(){
    auto temp = tplt();
    for(int i = 1; i <= n; i++){
        memset(visited, false, sizeof(visited));
        visited[i] = true;
        if(tplt() > temp){
            cout << i << " ";
        }
    }
    cout << endl;
}
int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        input();
        solution();
    }
}
