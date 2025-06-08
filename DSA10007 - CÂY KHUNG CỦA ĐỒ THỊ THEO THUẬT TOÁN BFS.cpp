#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int const mod = 1e9 + 7;

#define anhduck "Mai Anh Duc"

#define endl "\n"
#define ii pair<int,int>
#define iii pair<pair<int,int>>

int n, m, u;
vector <ii> res;
bool visited[10005], check;
vector <int> adj[10005];
void nhap(){
	check = false;
	for(int i = 0; i < 10005; i++){
		adj[i].clear();
	}
	memset(visited, false, sizeof(visited));
	cin >> n >> m >> u;
	for(int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}
void BFS(int u){
	queue <int> q;
	q.push(u);
	visited[u] = true;
	while(!q.empty()){
		auto top = q.front(); q.pop();
		for(auto v : adj[top]){
			if(!visited[v]){
				res.push_back({top, v});
				q.push(v);
				visited[v] = true;
			}
		}
	}
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		nhap();
		res.clear();
		BFS(u);
		for(int i = 1; i <= n; i++){
			if(!visited[i]){
				check = true;
				break;
			}
		}
		if(check) cout << -1 << endl;
		else{
			for(auto x : res){
				cout << x.first << " " << x.second << endl;
			}
		}
	}
}
