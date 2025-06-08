#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int const mod = 1e9 + 7;

#define anhduck "Mai Anh Duc"

#define endl "\n"
using ii = pair <int,int>;
using iii = pair <int, pair<int, int>>;
#define fi first
#define se second
int n, m;
vector <int> adj[10005];
void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        adj[i].clear();
    }
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i = 1; i <= n; i++){
        cout << i << ": ";
        for(auto it : adj[i]){
            cout << it << " ";
        }
        cout << endl;
    }
}
int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
