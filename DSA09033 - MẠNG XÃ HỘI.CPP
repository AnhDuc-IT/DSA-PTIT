#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m;
vector <int> adj[100005];
bool visited[100005];
void nhap(){
    memset(visited, false, sizeof(visited));
    for(int i = 0; i < 100005; i++){
        adj[i].clear();
    }
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}
void DFS(int u, int &sz, int &ans){
    visited[u] = true;
    ++ans;
    sz += adj[u].size();
    for(auto v : adj[u]){
        if(!visited[v]){
            DFS(v, sz, ans);
        }
    }
}
int main(){
    ios :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin >> t;
    while(t--){
        nhap();
        bool ok = true;
        int sz = 0, ans = 0;
        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                DFS(i, sz, ans);
                if(ans * (ans - 1) != sz){
                    ok = false;
                    break;
                }
                sz = 0, ans = 0;
            }
        }
        if(ok == true){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}
