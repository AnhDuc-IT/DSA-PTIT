#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl "\n"
#define ii pair<int,int>
#define iii pair<pair<int,int>>
struct node{
    int data;
    node *left;
    node *right;
    node(int x){
        this -> data = x;
    }
};
node* insertNode(node* root, int key){
    if(root == NULL) return new node(key);
    if(root -> data < key){
        root -> right = insertNode(root -> right, key);
    }
    else{
        root -> left = insertNode(root -> left, key);
    }
    return root;
}
void postOrder(node* root){
    if(root == NULL) return;
    postOrder(root -> left);
    postOrder(root -> right);
    cout << root -> data << " ";
}
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin >> t;
    while(t--){
        node *root = NULL;
        int n; cin >> n;
        int a[n];
        for(auto &x : a){
            cin >> x;
             root = insertNode(root, x);
        }
        postOrder(root);
        cout << endl;
    }
}
