#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, a[100];
void ktao(){
	for(int i = 1; i <= n; i++){
		a[i] = 0;
	}
}
bool check;
void generate(){
	int i = n;
	while(i >= 1 && a[i] == 1){
		a[i] = 0;
		--i;
	}
	if(i == 0) check = false;
	else{
		a[i] = 1;
	}
}
bool ok(){
	for(int i = 1; i <= n / 2; i++){
		if(a[i] != a[n - i + 1]) return false;
	}
	return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	cin >> n;
	ktao();
	check = true;
	while(check){
		if(ok()){
			for(int i = 1; i <= n; i++){
				cout << a[i] << " ";
			}
			cout << endl;
		}
		generate();
	}
}
