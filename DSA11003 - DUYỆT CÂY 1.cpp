#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int const mod = 1e9 + 7;
#define endl "\n"
#define ii pair<int,int>
#define iii pair<pair<int,int>>
struct node{
    int data;
    node* left;
    node* right;
    node(int x){
        this -> data = x;
        left = right = NULL;
    }
};
void makeRoot(node* root, int u, int v, char c){
    if(c == 'L'){
        root -> left = new node(v);
    }
    else root -> right = new node(v);
}
void insertNode(node* root, int u, int v, char c){
    if(root == NULL) return ;
    if(root -> data == u){
        makeRoot(root, u, v, c);
    }
    else{
        insertNode(root -> left, u, v, c);
        insertNode(root -> right, u, v, c);
    }
}
int In[1005], Pre[1005], n;
int Find(int a[], int x){
    for(int i = 0; i < n; i++){
        if(a[i] == x) return i;
    }
    return 0;
}
void Builtree(node* root, int in_left, int in_right){
    int in_pos = Find(In, root -> data);
    int pre_pos = Find(Pre, root -> data);
    if(in_pos > in_left){
        root -> left = new node(Pre[pre_pos + 1]);
        Builtree(root -> left, in_left, in_pos - 1);
    }
    if(in_pos < in_right){
        int contrai = in_pos - in_left;
        root -> right = new node(Pre[pre_pos + contrai + 1]);
        Builtree(root -> right, in_pos + 1, in_right);
    }
}
void Buildtree(node* root, int in_left, int in_right){
    int in_pos = Find(In, root -> data);
    int pre_pos = Find(Pre, root -> data);
    if(in_pos > in_left){
        root -> left = new node(Pre[pre_pos + 1]);
        Buildtree(root -> left, in_left, in_pos - 1);
    }
    if(in_pos < in_right){
        int tmp = in_pos - in_left;
        root -> right = new node(Pre[pre_pos + tmp + 1]);
        Buildtree(root -> right, in_pos + 1, in_right);
    }
}
void PosOrder(node* root){
    if(root == NULL) return;
    PosOrder(root -> left);
    PosOrder(root ->  right);
    cout << root -> data << " ";
}
int main(){
    ios :: sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> In[i];
        for(int i = 0; i < n; i++) cin >> Pre[i];
        node *root = new node(Pre[0]);
        Buildtree(root, 0, n - 1);
        PosOrder(root);
        cout << endl;
    }
}
