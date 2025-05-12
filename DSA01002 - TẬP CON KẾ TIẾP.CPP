#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int x[100], n, k;
void generate(){
    int i = k;
    while(i >= 1 && x[i] == n - k + i){
        --i;
    }
    if(i == 0){
        for(int i = 1; i <= k; i++){
            cout << i << " ";
        }
        cout << endl;
    }
    else{
        x[i]++;
        for(int j = i + 1; j <= k; j++){
            x[j] = x[j - 1] + 1;
        }
        for(int i = 1; i <= k; i++){
            cout << x[i] << " ";
        }
        cout << endl;
    }
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 1; i <= k; i++){
            cin >> x[i];
        }
        generate();
    }
}
