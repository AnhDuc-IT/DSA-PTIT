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
    if(c == 'R'){
        root -> right = new node(v);
    }
    else{
        root -> left = new node(v);
    }
}
void insertNode(node* root, int u, int v, char c){
    if(root == NULL) return;
    if(root -> value == u){
        makeNode(root, u, v, c);
    }
    insertNode(root ->left, u, v, c);
    insertNode(root -> right, u, v, c);
}
int height(node* root){
    if(root == NULL) return -1;
    int is_left = height(root -> left);
    int is_right = height(root -> right);
    return max(is_left, is_right) + 1;
}
bool check(node* root, int cnt, int h){
    if(root == NULL) return false;
    if(!root -> left && !root -> right){
        return cnt == h;
    }
    return check(root -> left, cnt + 1, h) && check(root -> right, cnt + 1, h);
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
        int h = height(root);
        cout << check(root, 0, h) << endl;
    }
}
