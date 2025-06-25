#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
#define endl "\n"
#define ii pair<int, int>
#define iii pair<int, pair<int,int>>

#define Duck "Mai Anh Duc"
int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(nullptr);
    vector <int> ke[1005];
    int n; cin >> n;
    int a[n + 1][n + 1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) cin >> a[i][j];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(a[i][j]){
                ke[i].push_back(j);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(auto it : ke[i]){
            cout << it << " ";
        }
        cout << endl;
    }
}
