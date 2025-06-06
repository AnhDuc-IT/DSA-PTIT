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
	bool cmp(pair<int,int> a, pair <int,int> b){
		return a.first < b.first;
	}
	void insertNode(node* root, int u, int v){
		if(root == NULL) return;
		if(root ->data == u){
			if(root -> left == NULL){
				root -> left = new node(v);
			}
			else if(root -> right == NULL){
				root -> right = new node(v);
			}
			return;
		}
		insertNode(root -> left, u, v);
		insertNode(root -> right, u , v);
	}
	int Find(node *root){
		if(root == NULL) return -1;
		int left = Find(root -> left);
		int right = Find(root -> right);
		return max(left, right) + 1;
	}
	vector <int> adj[100005];
	int n, m;
	bool visited[100005];
	void inp(){
		cin >> n;
		for(int i = 1; i < n; i++){
			int x, y; cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
	}
	void BFS(){
		queue <int> q;
		vector <int> dp(n + 1, -1);
		dp[1] = 0;
		q.push(1);
		while(!q.empty()){
			auto it = q.front(); q.pop();
			for(auto x : adj[it]){
				if(!visited[x]){
					dp[x] = dp[it] + 1;
					q.push(x);
					visited[x] = true;
				}
			}
		}
		cout << *max_element(begin(dp), end(dp)) << endl;
	}
	int main(){
		ios_base :: sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);
		int t; cin >> t;
		while(t--){
			for(int i = 0; i < 100005; i++){
				adj[i].clear();
			}
			memset(visited, false, sizeof(visited));
			inp();
			BFS();
		}
	}
