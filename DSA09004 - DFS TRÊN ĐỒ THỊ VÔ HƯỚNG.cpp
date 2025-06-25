#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int const mod = 1e9 + 7;
#define ii pair<int,int>
#define iii pair<pair<int,int>>
int n, m, s;
vector <int> ke[10005];
bool visited[10005];
void nhap(){
	for(int i = 0; i < 10005; i++){
		ke[i].clear();
	}
	memset(visited, false, sizeof(visited));
	cin >> n >> m >> s;
	for(int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
}
void DFS(int u){
	visited[u] = true;
	cout << u << " ";
	for(auto v : ke[u]){
		if(!visited[v]){
			DFS(v);
		}
	}
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while(t--){
		nhap();
		DFS(s);
		cout << endl;
	}
}
