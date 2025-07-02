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
    int t; cin >> t;
    cin.ignore();
    queue <int> q;
    while(t--){
        string s;
        getline(cin , s);
        stringstream ss (s);
        string m;
        vector <string> v;
        while(ss >> m){
            v.push_back(m);
        }
        if(v.size() == 2){
            int tmp = stoi(v[v.size() - 1]);
            q.push(tmp);
        }
        else{
            if(v.back() == "POP"){
                if(!q.empty()){
                    q.pop();
                }
            }
            else{
                if(!q.empty()){
                    cout << q.front() << endl;
                }
                else{
                    cout << "NONE\n";
                }
            }
        }
    }
}
