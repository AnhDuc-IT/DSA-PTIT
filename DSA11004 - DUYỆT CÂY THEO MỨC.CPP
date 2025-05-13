#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct node{
    int value;
    node* left;
    node* right;
    node(int x){
        this -> value = x;
        left = right = NULL;
    }
};
void makeNode(node* root, int u, int v, char c){
    if(c == 'L') root -> left = new node(v);
    else root -> right = new node(v);
}
void insertNode(node* root, int u, int v, char c){
    if(root == NULL) return;
    if(root -> value == u){
        makeNode(root, u, v, c);
    }
    else{
        insertNode(root -> left, u, v, c);
        insertNode(root -> right, u, v, c);
    }
}
void BFS(node* root){
    queue <node* > q;
    q.push(root);
    while(!q.empty()){
        auto it = q.front(); q.pop();
        cout << it -> value << " ";
        if(it -> left){
            q.push(it -> left);
        }
        if(it -> right){
            q.push(it -> right);
        }
    }
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin >> t;
    while(t--){
        node* root = NULL;
        int n; cin >> n;
        for(int i = 0; i < n; i++){
            int u, v; char c; cin >> u >> v >> c;
            if(!root){
                root = new node(u);
                insertNode(root, u, v, c);
            }
            else{
                insertNode(root, u, v, c);
            }
        }
        BFS(root);
        cout << endl;
    }
}
