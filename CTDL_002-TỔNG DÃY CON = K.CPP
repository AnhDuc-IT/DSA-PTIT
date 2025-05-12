#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, k, x[100], a[100];
int sum;
vector <int> tmp;
int cnt = 0;
vector <vector <int>> res;
void Try(int i, int pos){
	for(int j = pos; j <= n; j++){
		sum += a[j];
		tmp.push_back(a[j]);
		if(sum == k){
			res.push_back(tmp);
			++cnt;
		}
		else if(sum < k){
			Try(i + 1, j + 1);
		}
		tmp.pop_back();
		sum -= a[j];
	}
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	Try(1, 1);
	reverse(begin(res), end(res));
	for(auto x : res){
		for(auto it : x){
			cout << it << " ";
		}
		cout << endl;
	}
	cout << cnt << endl;
}
