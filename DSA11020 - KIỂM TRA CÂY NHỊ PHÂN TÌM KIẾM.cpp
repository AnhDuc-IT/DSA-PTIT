#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl "\n"
#define ii pair<int,int>
#define iii pair<pair<int,int>>
struct node{
	int data;
	node* left;
	node* right;
	node(int x){
		this -> data = x;
		this -> left = this -> right = NULL;
	}
};
bool check(int a[], int n){
	for(int i = 1; i < n; i++){
		if(a[i] <= a[i - 1]) return false;
	}
	return true;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int a[n];
		for(auto &x : a) cin >> x;
		cout << check(a,n) << endl;
	}
}
