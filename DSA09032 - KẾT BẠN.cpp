#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector <int> adj[100005];
int n, m, s;
bool visited[100005], check;
int parent[100005], sz[100005];
vector <pair<int,int>> res;
void nhap(){
    check = false;
    for(int i = 0; i < 10005; i++){
        adj[i].clear();
    }
    memset(visited, false, sizeof(visited));
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}
int cnt = 0;
void DFS(int u){
    visited[u] = true;
    ++cnt;
    for(auto x : adj[u]){
        if(!visited[x]){
            DFS(x);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        nhap();
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                DFS(i);
                ans = max(ans, cnt);
                cnt = 0;
            }
        }
        cout << ans << endl;
    }
}
