#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int const MOD =  123456789;
int n, m;
vector <int> ke[1005];
bool visited[1005];
int parent[1005];
int ok = 1;
void nhap(){
    ok = 1;
    memset(visited, false, sizeof(visited));
    for(int i = 0; i < 1005; i++){
        ke[i].clear();
    }
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
}
bool DFS(int u){
    visited[u] = true;
    for(auto x : ke[u]){
        if(!visited[x]){
            parent[x] = u;
            if(DFS(x)) return true;
        }
        else if(x != parent[u]){
            ok = 0;
            return true;
        }
    }
    return false;
}
int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        nhap();
        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                DFS(i);
            }
        }
        if(ok == 0) cout << "YES\n";
        else cout << "NO\n";
    }
}
