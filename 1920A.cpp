#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n; cin >> n;
    set<int> notequal;
    int lowerbound = 0;
    int higherbound = INT_MAX;
    for (int i = 0; i < n; i++){
        int type; cin >> type;
        if (type == 1){
            int temp; cin >> temp;
            lowerbound = max(temp, lowerbound);
        } else if (type == 2){
            int temp; cin >> temp;
            higherbound = min(higherbound, temp);
        } else{
            int temp; cin >> temp;
            notequal.insert(temp);
        }
    }
    int ans = higherbound - lowerbound + 1;
    for (int i : notequal){
        if (i >= lowerbound && i <= higherbound){
            ans -= 1;
        }
    }
    cout << max(0,ans) << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}