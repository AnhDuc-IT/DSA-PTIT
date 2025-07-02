#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 1e9 + 7;
#define ii pair<int,int>
#define iii pair <int, pair<int, int>>
void solve(int n){
    int ans = 0;
    queue <string> q;
    q.push("1");
    while(!q.empty()){
        auto x = q.front(); q.pop();
        if(ans == n){
            break;
        }
        ++ans;
        cout << x << " ";
        q.push(x + "0");
        q.push(x + "1");
    }
    cout << endl;
}
int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        solve(n);
    }
}
