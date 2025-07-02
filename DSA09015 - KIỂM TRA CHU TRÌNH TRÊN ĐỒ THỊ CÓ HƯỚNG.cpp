#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int const MOD = 1e9 + 7;
vector <int> ke[1005];
int degree[1005];
int n, m;
void nhap(){
    for(int i = 0; i < 1005; i++){
        degree[i] = 0;
        ke[i].clear();
    }
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        degree[y]++;
    }
}
void Kahn(){
    queue <int> q;
    vector <int> Topo;
    for(int i = 1; i <= n; i++){
        if(degree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        Topo.push_back(u);
        for(auto it : ke[u]){
            degree[it]--;
            if(degree[it] == 0){
                q.push(it);
            }
        }
    }
    if(Topo.size() < n){
        cout << "YES\n";
    }
    else cout << "NO\n";
}
int main(){
    ios :: sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        nhap();
        Kahn();
    }
}
