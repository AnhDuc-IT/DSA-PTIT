#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int const MOD =  123456789;
int n, m;
vector <int> ke[1005];
bool visited[1005];
int parent[1005];
int ok = 1;
int color[1005];
void nhap(){
    ok = 1;
    memset(visited, false, sizeof(visited));
    memset(color, 0, sizeof(color));
    for(int i = 0; i < 1005; i++){
        ke[i].clear();
    }
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
    }
}
bool DFS(int u){
    color[u] = 1;
    for(auto x : ke[u]){
        if(color[x] == 0){
            parent[x] = u;
            if(DFS(x)) return true; 
        }
        else if(color[x] == 1){
            ok = 0;
            return true;
        }
    }
    color[u] = 2;
    return false;
}
int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        nhap();
        for(int i = 1; i <= n; i++){
            if(color[i] == 0){
                DFS(i);
            }
        }
        if(ok == 0) cout << "YES\n";
        else cout << "NO\n";
    }
}
