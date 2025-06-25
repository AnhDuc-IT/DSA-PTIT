#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
#define endl "\n"
#define ii pair<int, int>
#define iii pair<int, pair<int,int>>

#define Duck "Mai Anh Duc"
int n, a[1005][1005];
void solve(){
    cin >> n;
    cin.ignore();
    for(int i = 1; i <= n; i++){
        string line;
        getline(cin, line);
        stringstream ss(line);
        int temp;
        while(ss >> temp){
            a[i][temp] = 1;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
