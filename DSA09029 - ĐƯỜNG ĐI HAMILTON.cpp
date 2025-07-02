#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m;
vector <int> ke[10005];
bool visited[10005];
bool check = false;
void nhap(){
    for(int i = 0; i < 10005; i++){
        ke[i].clear();
    }
    memset(visited, false, sizeof(visited));
    check = false;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
}
void DFS(int u, int cnt){
    if(cnt == n){
        check = true;
        return;
    }
    for(auto x : ke[u]){
        if(!visited[x]){
            visited[x] = true;
            DFS(x, cnt + 1);
            visited[x] = false;
        }
    }
}
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        nhap();
        for(int i = 1; i <= n; i++){
            memset(visited, false, sizeof(visited));
            visited[i] = true;
            DFS(i, 1);
            if(check) break;
        }
        cout << check << endl;
    }
}
