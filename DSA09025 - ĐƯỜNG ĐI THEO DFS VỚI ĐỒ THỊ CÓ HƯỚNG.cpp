#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int const mod = 1e9 + 7;
#define ii pair<int,int>
#define iii pair<pair<int,int>>
int n, m, s, t;
int parent[10005];
vector <ii> res;
bool visited[10005], check;
vector <int> adj[10005];
void nhap(){
	memset(visited, false, sizeof(visited));
	for(int i = 0; i < 10005; i++) adj[i].clear();
	cin >> n >> m >> s >> t;
	for(int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
	}
}
void DFS(int u){
	visited[u] = true;
	for(auto v : adj[u]){
		if(!visited[v]){
			parent[v] = u;
			DFS(v);
		}
	}
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while(T--){
		nhap();
		check = false;
		DFS(s);
		if(!visited[t]) cout << "-1\n";
		else{
			vector <int> res;
			while(t != s){
				res.push_back(t);
				t = parent[t];
			}
			res.push_back(t);
			reverse(begin(res), end(res));
			for(auto x : res){
				cout << x << " ";
			}
			cout << endl;
		}
	}
}
