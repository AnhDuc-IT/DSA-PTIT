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
int n, m;
vector <int> adj[10005];
void solve(){
    cin >> n;
    vector <ii> v;
    cin.ignore();
    for(int i = 1; i <= n; i++){
        string s; getline(cin, s);
        stringstream ss(s);
        string temp;
        while(ss >> temp){
            if(stoi(temp) > i){
                v.push_back({i, stoi(temp)});
            }
        }
    }
    for(auto x : v){
        cout << x.first << " " << x.second << endl;
    }
}
int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
