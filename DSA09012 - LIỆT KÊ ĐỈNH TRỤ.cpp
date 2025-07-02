#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int const mod = 1e9 + 7;
#define ii pair<int,int>
#define iii pair<pair<int,int>>
int n, m;
bool visited[10005];
vector <int> adj[10005];
void nhap(){
	memset(visited, false, sizeof(visited));
	for(int i = 0; i < 10005; i++){
		adj[i].clear();
	}
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}
void DFS(int u){
	visited[u] = true;
	for(auto v : adj[u]){
		if(!visited[v]){
			DFS(v);
		}
	}
}
int tplt(){
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			++cnt;
			DFS(i);
		}
	}
	return cnt;
}
void dinhtru(){
	int ans =  tplt();
	for(int i = 1; i <= n; i++){
		memset(visited, false, sizeof(visited));
		visited[i] = true;
		if(tplt() > ans){
			cout << i << " ";
		}
	}
	cout << endl;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int testcase; cin >> testcase;
	while(testcase--){
		nhap();
		dinhtru();
	}
}
