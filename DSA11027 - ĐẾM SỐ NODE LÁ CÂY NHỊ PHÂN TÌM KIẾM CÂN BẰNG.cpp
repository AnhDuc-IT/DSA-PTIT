#include <bits/stdc++.h>
	using namespace std;
	using ll = long long;
	struct node{
		int data;
		node *left;
		node *right;
		node(int x){
			this -> data = x;
			left = right = NULL;
		}
	};
	node* makeNode(int a[], int l, int r){
		if(l > r) return NULL;
		int m = (l + r) / 2;
		node *root = new node(a[m]);
		root -> left = makeNode(a, l, m - 1);
		root -> right = makeNode(a, m + 1, r);
		return root;
	}
	int Count(node* root){
		int cnt = 0;
		if(root == NULL) return 0;
		if(!root -> left && root -> right == NULL){
			cnt = 1;
		}
		cnt += Count(root -> left);
		cnt += Count(root -> right);
		return cnt;
	}
	int main(){
		ios_base :: sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);
		int t; cin >> t;
		while(t--){
			int n; cin >> n;
			int a[n];
			for(auto &x : a) cin >> x;
			sort(a, a + n);
			node *root = NULL;
			root = makeNode(a, 0, n - 1);
			cout << Count(root) << endl;
		}
	}
