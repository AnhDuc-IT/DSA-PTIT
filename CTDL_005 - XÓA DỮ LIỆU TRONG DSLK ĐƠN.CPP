#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k; cin >> n;
    int a[n];
    vector <int> v;
    bool used[1005] = {false};
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> k;
    for(auto x : a){
        if(x != k) cout << x << " ";
    }
}