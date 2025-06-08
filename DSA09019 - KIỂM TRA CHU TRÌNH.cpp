#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int const mod = 1e9 + 7;

#define anhduck "Mai Anh Duc"

#define endl "\n"
#define ii pair<int,int>
#define iii pair<pair<int,int>>

int n, m, parent[10005], sz[10005];
vector <int> adj[10005];
bool visited[10005];
void start(){
    for(int i = 1; i <= n; i++){
        sz[i] = 1;
        parent[i] = i;
    }
}
int Find(int u){
    if(u == parent[u]) return u;
    return parent[u] = Find(parent[u]);
}
bool Union(int u, int v){
    u = Find(u);
    v = Find(v);
    if(u == v) return false;
    if(sz[u] < sz[v]) swap(u, v);
    sz[u] += sz[v];
    parent[v] = u;
    return true;
}
int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        bool check = false;
        cin >> n >> m;
        start();
        for(int i = 0; i < m; i++){
            int x, y; cin >> x >> y;
            if(!Union(x, y)) check = true;
        }
        if(check) cout << "YES\n";
        else cout << "NO\n";
    }
}a
