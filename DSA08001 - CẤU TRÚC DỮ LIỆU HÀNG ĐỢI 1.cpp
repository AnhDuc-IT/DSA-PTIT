#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 1e9 + 7;
#define ii pair<int, int>
#define iii pair<int, pair<int, int>>
int solve(int s, int t){
    queue <ii> q;
    q.push({s, 0});
    set <int> used;
    while(!q.empty()){
        ii x = q.front(); q.pop();
        int a = x.first, b = x.second;
        if(a == t){
            return b;
        }
        if(a > 1 && used.count(a - 1) == 0){
            q.push({a - 1, b + 1});
            used.insert(a - 1);
        }
        if(a < t && used.count(a * 2) == 0){
            q.push({a * 2, b + 1});
        }
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    while(T--){
        queue <int> q;
        vector <int> v;
        int n; cin >> n;
        for(int i = 0; i < n; i++){
            int x, y; cin >> x;
            if(x == 1){
                cout << q.size() << endl;
            }
            else if(x == 2){
                if(q.empty()){
                    cout << "YES\n";
                }
                else cout << "NO\n";
            }
            else if(x == 3){
                int y; cin >> y;
                q.push(y);
                v.push_back(y);
            }
            else if(x == 4){
                if(!q.empty()){
                    q.pop();
                }
            }
            else if(x == 5){
                if(q.empty()){
                    cout << "-1\n";
                }
                else{
                    cout << q.front() << endl;
                }
            }
            else{
                if(q.empty()){
                    cout << "-1\n";
                }
                else{
                    cout << v.back() << endl;
                }
            }
        }
    }
}
