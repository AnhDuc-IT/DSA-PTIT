#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int const mod = 1e9 + 7;
#define ii pair<int,int>
#define iii pair<pair<int,int>>
#define endl "\n"
struct node{
	int data;
	node* left;
	node* right;
	node(int x){
		this -> data = x;
		this -> left = this -> right = NULL;
	}
};
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		set <int> se;
		for(int i = 0; i < n; i++){
			int u, v; char c; cin >> u >> v >> c;
			se.insert(u);
			se.insert(v);
		}
		for(auto x : se){
			cout << x << " ";
		}
		cout << endl;
	}
}
