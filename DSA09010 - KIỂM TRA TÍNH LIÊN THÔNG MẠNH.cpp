#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int const MOD =  123456789;
int n, m;
bool visited[1005];
vector <int> ke[1005];
vector <int> t_ke[1005];
stack <int> st;
void nhap(){
    memset(visited, false, sizeof(visited));
    for(int i = 0; i < 1005; i++){
        ke[i].clear();
        t_ke[i].clear();
    }
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        t_ke[y].push_back(x);
    }
}
void DFS(int u){
    visited[u] = true;
    for(auto x : ke[u]){
        if(!visited[x]){
            DFS(x);
        }
    }
    st.push(u);
}
void Kosaraju(int u){
    visited[u] = true;
    for(auto x : t_ke[u]){
        if(!visited[x]){
            Kosaraju(x);
        }
    }
}
int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        nhap();
        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                DFS(i);
            }
        }
        memset(visited, false, sizeof(visited));
        int dem = 0;
        while(!st.empty()){
            auto it = st.top();
            st.pop();
            if(!visited[it]){
                ++dem;
                Kosaraju(it);
            }
        }
        if(dem == 1) cout << "YES\n";
        else cout << "NO\n";
    }
}
