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
node* makeNode(node* root, int u){
	if(!root) return new node(u);
	if(root -> data < u) root -> right = makeNode(root -> right,u);
	else root -> left = makeNode(root -> left, u);
	return root;
}
void lastOrder(node* root){
	if(!root) return;
	lastOrder(root -> left);
	lastOrder(root -> right);
	cout << root -> data << " ";
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
			root =  makeNode(root, v);
		}
		lastOrder(root);
		cout << endl;
	}
}
