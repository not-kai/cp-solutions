#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n,k; cin >> n >> k;
    if (n == k){
        for (int i = 0; i < n; i++){
            cout << 1 << " ";
        }
        cout << "\n";
        return;
    } else if (k == 1){
        for (int i = 1; i <= n; i++){
            cout << i << " ";
        }
        cout << "\n";
    } else{
        cout << "-1" << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}