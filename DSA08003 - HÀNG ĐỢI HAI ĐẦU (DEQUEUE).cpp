#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 1e9 + 7;
#define ii pair<int,int>
#define iii pair <int, pair<int, int>>
int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);
    deque <int> dq;
    int q;
    cin >> q;
    cin.ignore();
    while(q--){
        string s; getline(cin, s);
        stringstream ss (s);
        string token;
        vector <string> v;
        while(ss >> token){
            v.push_back(token);
        }
        if(v.size() == 2){
            if(v[0].back() == 'T'){
                dq.push_front(stoi(v.back()));
            }
            else{
                dq.push_back(stoi(v.back()));
            }
        }
        else{
            if(v.back()[1] == 'O'){
                if(v.back().back() == 'T'){
                    if(dq.size() > 0){
                        dq.pop_front();
                    }
                }
                else{
                    if(dq.size() > 0){
                        dq.pop_back();
                    }
                }
            }
            else{
                if(v.back().back() == 'T'){
                    if(dq.size() > 0){
                        cout << dq.front() << endl;
                    }
                    else{
                        cout << "NONE\n";
                    }
                }
                else{
                    if(dq.size() > 0){
                        cout << dq.back() << endl;
                    }
                    else{
                        cout << "NONE\n";
                    }
                }
            }
        }
    }
}
