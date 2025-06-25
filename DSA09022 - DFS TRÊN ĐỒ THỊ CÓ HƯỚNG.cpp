#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
#define endl "\n"
#define ii pair<int, int>
#define iii pair<int, pair<int,int>>

#define Duck "Mai Anh Duc"
vector <int> ke[1005];
bool visited[1005];
int n, m, u;
void nhap(){
    cin >> n >> m >> u;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
    }
}
void DFS(int u){
    cout << u << " ";
    visited[u] = true;
    for(auto x : ke[u]){
        if(!visited[x]){
            DFS(x);
        }
    }
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        memset(visited, false, sizeof(visited));
        nhap();
        DFS(u);
        for(int i = 0; i < 1005; i++){
            ke[i].clear();
        }
        cout << endl;
    }
}
