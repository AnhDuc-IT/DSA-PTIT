#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int const MOD = 1e9 + 7;
int n, m;
vector <int> ke[1005];
bool visited[1005];
int parent[1005];
int dem = 0;
int pos[1005];
void nhap(){
    memset(visited, false, sizeof(visited));
    for(int i = 0; i < 1005; i++){
        ke[i].clear();
    }
    dem = 0;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
}
void BFS(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        pos[it] = dem;
        for(auto x : ke[it]){
            if(!visited[x]){
                q.push(x);
                visited[x] = true;
            }
        }
    }
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        nhap();
        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                ++dem;
                BFS(i);
            }
        }
        cout << dem << endl;
    }
}
