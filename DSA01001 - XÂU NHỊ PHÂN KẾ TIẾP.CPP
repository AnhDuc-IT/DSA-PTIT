#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int const MOD  = 1e9 + 7;
string s;
bool check;
void generate(){
	int n = s.size() - 1;
	int i = n;
	while(i >= 0 && s[i] == '1'){
		s[i] = '0';
		--i;
	}
	if(i == -1) check = false;
	else{
		s[i] = '1';
	}
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	int t; cin >>  t;
	while(t--){
		cin >> s;
		check = true;
		generate();
		if(check == false){
			for(int i = 0; i < s.size(); i++){
				cout << 0;
			}
			cout << endl;
		}
		else{
			cout << s << endl;
		}
	}
}

