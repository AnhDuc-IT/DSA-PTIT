#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int const mod = 1e9 + 7;
#define ii pair<int,int>
#define iii pair<pair<int,int>>
int n, m, a[1005][1005];
bool visited[1005][1005];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
void nhap(){
	memset(visited, false, sizeof(visited));
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++) cin >> a[i][j];
	}
}
void DFS(int i, int j){
	visited[i][j] = true;
	for(int k = 0; k < 8; k++){
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if(i1 <= n && i1 >= 1 && j1 <= m && j1 >= 1 && a[i1][j1] && !visited[i1][j1]){
			DFS(i1, j1);
		}
	}
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int testcase; cin >> testcase;
	while(testcase--){
		nhap();
		int cnt = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(a[i][j] && !visited[i][j]){
					++cnt;
					DFS(i, j);
				}
			}
		}
		cout << cnt << endl;
	}
}
