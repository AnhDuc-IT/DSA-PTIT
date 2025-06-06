#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(int a[], int l, int r){
	if(l > r) return;
	int m = (l + r) / 2;
	cout << a[m] << " ";
	solve(a, l, m - 1);
	solve(a, m + 1, r);

}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int a[n];
		for(auto &x : a) cin >> x;
		sort(a, a + n);
		solve(a, 0, n - 1);
		cout << endl;
	}
}
