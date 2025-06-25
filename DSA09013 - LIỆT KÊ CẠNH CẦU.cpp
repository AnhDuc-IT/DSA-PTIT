#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int const MOD = 1e9 + 7;
int n, m, dem = 0;
set <int> ke[1005];
vector <pair<int, int>> dscanh;
bool visited[1005];
void nhap(){
    memset(visited, false, sizeof(visited));
    for(int i = 0; i < 1005; i++){
        ke[i].clear();
    }
    dscanh.clear();
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        dscanh.push_back({x, y});
        ke[x].insert(y);
        ke[y].insert(x);
    }
}
void BFS(int u){
    queue <int> q;
    q.push(u);
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        for(auto x : ke[it]){
            if(!visited[x]){
                q.push(x);
                visited[x] = true;
            }
        }
    }
}
int tplt(){
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            ++cnt;
            BFS(i);
        }
    }
    return cnt;
}
void canhcau(){
    auto ans = tplt();
    for(auto it : dscanh){
        auto x = it.first;
        auto y = it.second;
        ke[x].erase(y);
        ke[y].erase(x);
        memset(visited, false, sizeof(visited));
        if(ans < tplt()){
            cout << x << ' ' << y << " ";
        }
        ke[x].insert(y);
        ke[y].insert(x);
    }
}
int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(nullptr);
    int q; cin >> q;
    while(q--){
        nhap();
        canhcau();
        cout << endl;
    }
}
