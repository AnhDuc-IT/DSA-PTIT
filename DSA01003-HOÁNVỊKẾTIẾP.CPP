#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int a[100], n, k;
void generate(){
	int i = n - 1;
	while(i >= 1 && a[i] > a[i + 1]){
		--i;
	}
	if(i == 0){
		for(int j = 1; j <= n; j++){
			cout << j << ' ';
		}
		cout << endl;
	}
	else{
		int j = n;
		while(a[i] > a[j]){
			--j;
		}
		swap(a[i], a[j]);
		reverse(a + 1 + i, a + n + 1);
		for(int j = 1; j <= n; j++){
			cout << a[j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    int t; cin >> t;
    while(t--){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		generate();
    }
}