#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int s1, s2, t1, t2;
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
bool used[1005][1005];
int BFS(){
    memset(used, false, sizeof(used));
    queue <pair<pair<int, int>, int>> q;
    q.push({{s1, s2}, 0});
    used[s1][s2] = true;
    while(!q.empty()){
        auto it = q.front(); q.pop();
        int i = it.first.first, j = it.first.second, len = it.second;
        if(i == t1 && j == t2) return len;
        for(int k = 0; k < 8; k++){
            int i1 = i + dx[k];
            int j1 = j + dy[k];
            if(i1 >= 1 && i1 <= 8 && j1 >= 1 && j1 <= 8 && used[i1][j1] == false){
                q.push({{i1, j1}, len + 1});
                used[i1][j1] = true;
            }
        }
    }
    return -1;
}
void solve(){
    string st, en; cin >> st >> en;
    s1 = st[1] - '0', s2 = st[0] - 'a' + 1;
    t1 = en[1] - '0', t2 = en[0] - 'a' + 1;
    cout << BFS() << endl;
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
