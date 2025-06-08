#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int const mod = 1e9 + 7;

#define anhduck "Mai Anh Duc"

#define endl "\n"
#define ii pair<int,int>
#define iii pair<pair<int,int>>

int n, m, u;
bool visited[10005];
vector <ii> ke[10005];
void nhap(){
	memset(visited, false, sizeof(visited));
	for(int i = 0; i < 10005; i++){
		ke[i].clear();
	}
	cin >> n >> m >> u;
	for(int i = 0; i < m; i++){
		int x, y, w; cin >> x >> y >> w;
		ke[x].push_back({y, w});
		ke[y].push_back({x, w});
	}
}
void Djikstra(int u){
	vector <int> d(n + 1, 1e9);
	d[u] = 0;
	priority_queue <ii, vector<ii>, greater<ii>> q;
	q.push({0, u});
	while(!q.empty()){
		auto u = q.top(); q.pop();
		auto dis = u.first, v = u.second;
		if(dis > d[v]) continue;
		for(auto x : ke[v]){
			auto s = x.first, kc = x.second;
			if(d[s] > d[v] + kc){
				d[s] = d[v] + kc;
				q.push({d[s], s});
			}
		}
	}
	for(int i = 1;i <= n; i++){
		cout << d[i] << " ";
	}
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int testcase; cin >> testcase;
	while(testcase--){
		nhap();
		Djikstra(u);
		cout << endl;
	}
}
