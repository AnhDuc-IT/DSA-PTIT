#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int const mod = 1e9 + 7;

#define anhduck "Mai Anh Duc"

#define endl "\n"
#define ii pair<int,int>
#define iii pair<pair<int,int>>

 int d[1005][1005];
    int n, m;
    void nhap(){
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i == j) d[i][j] = 0;
                else d[i][j] = 1e9;
            }
        }
        for(int i = 1; i <= m; i++){
            int x, y, w; cin >> x >> y >> w;
            d[x][y] = d[y][x] = w;
        }
    }
    void Floyd(){
        for(int k = 1; k <= n; k++){
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }
    int main(){
        ios :: sync_with_stdio(false);
        cin.tie(NULL);
        nhap();
        Floyd();
        int q; cin >> q;
        while(q--){
            int x, y; cin >> x >> y;
            cout << d[x][y] << endl;
        }
    }
