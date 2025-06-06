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
void makeNode(node *root, int u, int v, char c){
    if(c == 'L'){
        root -> left = new node(v);
    }
    else{
        root -> right = new node(v);
    }
}
void insertNode(node* root, int u, int v, char c){
    if(root == NULL) return;
    if(root -> data == u){
        makeNode(root, u, v, c);
    }
    else{
        insertNode(root -> left, u, v, c);
        insertNode(root -> right,u, v, c);
    }
}
int ans;

int sum(node *root){
    if(root == NULL) return 0;
    if(root -> left == NULL && root -> right == NULL){
        return root -> data;
    }
    int sum_left = sum(root -> left);
    int sum_right = sum(root -> right);
    if(root -> left && root -> right){
        ans = max(ans, sum_left + sum_right + root -> data);
        return max(sum_left, sum_right) + root ->data;
    }
    if(root -> left){
        return sum_left + root -> data;
    }
    else{
        return sum_right + root -> data;
    }
}
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        node* root = NULL;
        ans = INT_MIN;
        for(int i = 0; i < n; i++){
            int u, v; char c; cin >> u >> v >> c;
            if(root == NULL){
                root = new node(u);
                insertNode(root, u, v, c);
            }
            else{
                insertNode(root, u, v, c);
            }
        }
        sum(root);
        cout << ans << endl;
    }
}
