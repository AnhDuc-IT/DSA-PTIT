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
        data = x;
        left = right = NULL;
    }
};
void makeNode(node* root, int u, int v, char c){
    if(c == 'L'){
        root -> left = new node(v);
    }
    else {
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
        insertNode(root -> right, u, v, c);
    }
}
void Build(node* root, int x){
    if(root -> data < x){
        if(root -> right) Build(root -> right, x);
        else root -> right = new node(x);
    }
    else{
        if(root -> left) Build(root -> left, x);
        else root -> left = new node(x);
    }
}
void inOrder(node* root){
    if(root == NULL) return;
    inOrder(root -> left);
    cout << root -> data << " ";
    inOrder(root -> right);
}
bool check(vector <int> &a, int n){
    for(int i = 0; i < n - 1; i++){
        if(a[i] >= a[i + 1]) return false;
    }
    return true;
}
string solve(string s){
    stack <string> st;
    for(char x : s){
        if(isalpha(x)){
            string tmp = "";
            tmp += x;
            st.push(tmp);
        }
        else{
            string b = st.top(); st.pop();
            string a = st.top(); st.pop();
            string tmp = "";
            tmp += a + x + b;
            st.push(tmp);
        }
    }
    return st.top();
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--){  
        string s; cin >> s;
        string tmp = solve(s);
        string res = "";
        cout << tmp << endl;
    }
}
