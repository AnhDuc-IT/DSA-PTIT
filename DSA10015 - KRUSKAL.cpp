#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int const mod = 1e9 + 7;

#define anhduck "Mai Anh Duc"

#define endl "\n"
#define ii pair<int,int>
#define iii pair<pair<int,int>>

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
void nhap(){
    e.clear();
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y, w; cin >> x >> y >> w;
        edge tmp({x, y, w});
        e.push_back(tmp);
    }
}
void Kruskal(){
    sort(begin(e), end(e), [](edge a, edge b)->bool{
        return a.w < b.w;
    });
    ll d = 0;
    vector <edge> MST;
    for(int i = 0; i < m; i++){
        if(MST.size() == n - 1){
            break;
        }
        edge tmp = e[i];
        if(Union(tmp.x, tmp.y)){
            d += tmp.w;
            MST.push_back(tmp);
        }
    }
    cout << d << endl;
}
int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        nhap();
        ktao();
        Kruskal();
    }
}
