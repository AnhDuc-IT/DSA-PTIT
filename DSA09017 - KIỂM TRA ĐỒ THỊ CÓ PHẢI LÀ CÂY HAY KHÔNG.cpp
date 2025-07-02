#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int const mod = 1e9 + 7;
#define ii pair<int,int>
#define iii pair<pair<int,int>>
int n, m, parent[10005], sz[10005];
vector <int> ke[10005];
bool visited[10005];
void nhap(){
	for(int i = 0; i < 10005; i++) ke[i].clear();
	memset(visited, false, sizeof(visited));
	cin >> n;
}
void ktao(){
	for(int i = 1; i <= n; i++){
		sz[i] = 1;
		parent[i] = i;
	}
}
int Find(int u){
	if(u == parent[u]) return u;
	return parent[u] = Find(parent[u]);
}
bool Union(int u, int v){
	u = Find(u);
	v = Find(v);
	if(u == v) return false;
	if(sz[u] < sz[v]){
		swap(u, v);
	}
	sz[u] += sz[v];
	parent[v] = u;
	return true;
}
void DFS(int u){
	visited[u] = true;
	for(auto v : ke[u]){
		if(!visited[v]){
			DFS(v);
		}
	}
}
bool check(){
    DFS(1);
	for(int i = 1; i <= n;i++){
		if(!visited[i]){
			return false;
		}
	}	
	return true;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while(t--){
	nhap();
	ktao();
	bool ok = false;
	int m = n - 1;
	for(int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
		if(!Union(x, y)) ok = true;
	}
	if(check() && !ok) cout << "YES\n";
	else cout << "NO\n";
	ok = false;
	}
}
