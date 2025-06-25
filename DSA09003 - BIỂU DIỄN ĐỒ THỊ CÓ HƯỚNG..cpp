#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int const MOD = 1e9 + 7;
bool F[1005][40005];
int main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int v, e; cin >> v >> e;
        vector <int> ke[1005];
        for(int i = 0; i < e; i++){
            int x, y; cin >> x >> y;
            ke[x].push_back(y);
        }
        for(int i = 1; i <= v; i++){
            cout << i << ": ";
            for(int j = 0; j < ke[i].size(); j++){
                cout << ke[i][j] << " ";
            }
            cout << endl;
        }
        for(int i = 0; i < 1005; i++){
            ke[i].clear();
        }
    }
}
