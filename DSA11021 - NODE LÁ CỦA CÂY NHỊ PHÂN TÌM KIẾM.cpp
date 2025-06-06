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
node *makeNode(node *root, int v){
	if(!root) return new node(v);
	if(root -> data < v) root -> right = makeNode(root -> right, v);
	else root -> left = makeNode(root -> left, v);
	return root;
}
void solve(node* root){
	if(!root) return;
	if(!root -> left && !root -> right) cout << root -> data << " ";
	solve(root -> left);
	solve(root -> right);
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		node *root = NULL;
		for(int i = 0; i < n; i++){
			int v; cin >> v;
			root = makeNode(root, v);
		}
		solve(root);
		cout << endl;
	}
}
