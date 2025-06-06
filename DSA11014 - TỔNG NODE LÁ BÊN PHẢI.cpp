#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl "\n"
#define ii pair<int,int>
#define iii pair<pair<int,int>>
struct node {
    int data;
    node* left;
    node* right;
    node(int x) {
        data = x;
        left = right = NULL;
    }
};
void makeNode(node *&root, int n){
    map <int,node*> mp;
    for(int i = 0; i < n; i++){
        int u, v; char c; cin >> u >> v >> c;
        if(mp.find(u) == mp.end()){
            root = new node(u);
            if(c == 'L'){
                root -> left = new node(v);
                mp[v] = root -> left;
            }
            else{
                root -> right = new node(v);
                mp[v] = root -> right;
            }
            mp[u] = root;
        }
        else{
            if(c == 'L'){
                mp[u] -> left = new node(v);
                mp[v] = mp[u] -> left;
            }
            else{
                mp[u] -> right = new node(v);
                mp[v] = mp[u] -> right;
            }
        }
    }
}
bool isright(node *root){
    if(root == NULL) return false;
    if(root -> left == NULL && root ->  right == NULL) return true;
    return false;
}
int sum(node *root){
    int cnt = 0;
    if(root == NULL) return 0;
    if(isright(root -> right)){
        cnt = root -> right -> data;
    }
    if(root -> right){
        cnt += sum(root -> right);
    }
    if(root -> left && isright(root -> left) == false){
        cnt += sum(root -> left);
    }
    return cnt;
}
int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        node *root = NULL;
        makeNode(root, n);
        cout << sum(root) << endl;
    }
}
