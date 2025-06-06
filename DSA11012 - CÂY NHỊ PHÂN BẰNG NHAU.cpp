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
void makeNode(node* root, int u, int v, char c){
	if(c == 'L') root -> left = new node(v);
	else root -> right = new node(v);
}
void insertNode(node* root, int u, int v, char c){
	if(!root) return;
	if(root -> data == u) makeNode(root, u, v, c);
	insertNode(root -> left, u, v, c);
	insertNode(root -> right,u, v, c);
}
void nhap(node*& root){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		int u, v; char c; cin >> u >> v >> c;
		if(!root) root = new node(u);
		insertNode(root, u, v, c);
	}
}
bool check(node* root1, node* root2){
	if(!root1 && !root2) return true;
	if(!root1 || !root2) return false;
	if(root1 -> data != root2 -> data) return false;
	return check(root1 -> left, root2 -> left) && check(root1 -> right, root2 -> right);
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while(t--){
		node *root1 = NULL;
		node *root2 = NULL;
		nhap(root1);
		nhap(root2);
		cout << check(root1, root2) << endl;
	}
}
