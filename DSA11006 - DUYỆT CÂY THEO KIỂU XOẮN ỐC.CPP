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
void Spiorder(node* root){
    stack <node*> st1;
    stack <node*> st2;
    st1.push(root);
    while(!st1.empty() || !st2.empty()){
        while(!st1.empty()){
            node* tmp = st1.top(); st1.pop();
            cout << tmp -> value << " ";
            if(tmp -> right){
                st2.push(tmp -> right);
            }
            if(tmp -> left){
                st2.push(tmp -> left);
            }
        }
        while(!st2.empty()){
            node* tmp = st2.top(); st2.pop();
            cout << tmp -> value << " ";
            if(tmp -> left){
                st1.push(tmp -> left);
            }
            if(tmp -> right){
                st1.push(tmp -> right);
            }
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
        Spiorder(root);
        cout << endl;
    }
}
