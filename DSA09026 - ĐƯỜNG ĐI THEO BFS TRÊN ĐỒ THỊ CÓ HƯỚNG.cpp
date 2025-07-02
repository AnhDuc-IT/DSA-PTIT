#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int const MOD = 1e9 + 7;
int n, m, s, t;
vector <int> ke[1005];
int parent[1005];
bool visited[1005];
void nhap(){
    memset(visited, false, sizeof(visited));
    for(int i = 0; i < 1005; i++){
        ke[i].clear();
    }
    cin >> n >> m >> s >> t;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
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
                parent[x] = it;
                visited[x] = true;
            }
        }
    }
}
int main()
{
    ios :: sync_with_stdio(false);
    cin.tie();
    int q; cin >> q;
    while(q--){
        nhap();
        BFS(s);
        if(visited[t] == false) cout << "-1\n";
        else{
            vector <int> res;
            while(t != s){
                res.push_back(t);
                t = parent[t];
            }
            res.push_back(s);
            reverse(begin(res), end(res));
            for(auto it : res){
                cout << it << " ";
            }
            cout << endl;
        }
    }
}
