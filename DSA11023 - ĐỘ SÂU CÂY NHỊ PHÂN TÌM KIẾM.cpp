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
node* makeNode(node* root, int x){
	if(!root) return new node(x);
	if(root -> data < x){
		root -> right = makeNode(root -> right, x);
	}
	else root -> left = makeNode(root -> left, x);
	return root;
}
int height(node* root){
	if(!root) return -1;
	int left = height(root -> left);
	int right = height(root -> right);
	return max(left, right) + 1;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		node* root = NULL;
		for(int i = 0; i < n; i++){
			int x; cin >> x;
			root = makeNode(root, x);
		}
		cout << height(root) << endl;
	}
}
