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
int a[1005][1005];
int d[1005][1005];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int n, m;
vector <ii> ke[10005];
void nhap(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            d[i][j] = 1e9;
        }
    }
}
void Dijkstra(int i, int j){
    d[i][j] = a[i][j];
    priority_queue <iii, vector <iii>, greater <iii>> Q;
    Q.push({d[i][j], {i, j}});
    while(!Q.empty()){
        iii tmp = Q.top(); Q.pop();
        int dis = tmp.first;
        int u = tmp.second.first, v = tmp.second.second;
        if(dis > d[u][v]) continue;
        for(int k = 0; k < 4; k++){
            int u1 = u + dx[k];
            int v1 = v + dy[k];
            if(u1 >= 1 && u1 <= n && v1 >= 1 && v1 <= m){
                if(d[u1][v1] > d[u][v] + a[u1][v1]){
                    d[u1][v1] = d[u][v] + a[u1][v1];
                    Q.push({d[u1][v1], {u1, v1}});
                }
            }
        }
    }
    cout << d[n][m] << endl;
}
int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        nhap();
        Dijkstra(1, 1);
    }
}
