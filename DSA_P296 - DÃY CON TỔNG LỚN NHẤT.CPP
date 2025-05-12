#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	int n, q; cin >> n >> q;
	int a[n + 1];
	int dp[n + 1];
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		dp[i] = a[i];
	}
	for(int i = 2; i <= n; i++){
		dp[i] = max(dp[i - 1], dp[i - 1] + a[i]);
	}
	while(q--){
		int l, r; cin >> l >> r;
		cout << dp[r] - dp[l - 1] << endl;
	}
}
