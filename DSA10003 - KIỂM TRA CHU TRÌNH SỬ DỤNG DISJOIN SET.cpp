#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int const MOD = 1e9 + 7;
using ii = pair <int, int>;
int n, m, k, parent[10005], sz[10005];
struct edge{
    int x, y, w;
};
vector <edge> e;
void ktao(){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1;
    }
}
int Find(int u){
    if(u == parent[u]){
        return u;
    }
    return parent[u] = Find(parent[u]);
}
bool Union(int u, int v){
    u = Find(u);
    v = Find(v);
    if(u == v){
        return false;
    }
    if(sz[u] < sz[v]){
        swap(u, v);
    }
    sz[u] += sz[v];
    parent[v] = u;
    return true;
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin >> t;
    while(t--){
        cin >> n >> m;
        ktao();
        int ok = 0;
        for(int i = 0; i < m; i++){
            int x, y; cin >> x >> y;
            if(Union(x, y) == false){
                ok = 1;
            }
        }
        if(ok == 0){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
    }
}
