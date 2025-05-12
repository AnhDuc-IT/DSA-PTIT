#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int n, m;
bool visited[1005][1005];
char a[1005][1005];
void DFS(int i, int j){
	visited[i][j] = true;
	for(int k = 0; k < 4; k++){
		int i1 = dx[k] + i;
		int j1 = dy[k] + j;
		if(!visited[i1][j1] && a[i][j] == '#'){
			DFS(i1, j1);
		}
	}
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++) cin >> a[i][j];
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(!visited[i][j] && a[i][j] == '#'){
				DFS(i, j);
				++cnt;
			}
		}
	}
	cout << cnt << endl;
}
