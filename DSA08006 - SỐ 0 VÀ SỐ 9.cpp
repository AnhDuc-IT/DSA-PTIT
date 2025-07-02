#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int pre(char c){
    if(c == '*' || c == '/') return 2;
    if(c == '+' || c == '-') return 1;
    if(c == '^') return 3;
    return 0;
}
void solve(int n){
    queue <string> q;
    q.push("9");
    while(!q.empty()){
        auto tmp = q.front(); q.pop();
        ll ans = stoll(tmp);
        if(ans % n == 0){
            cout << ans << endl; return;
        }
        q.push(tmp + "0");
        q.push(tmp + "9");
    }
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t; cin >>  t;
    while(t--){
        int n; cin >> n;
        solve(n);
    }
}
