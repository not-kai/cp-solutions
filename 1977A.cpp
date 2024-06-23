#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n,m; cin >> n >> m;
    if (m > n){
        cout << "NO" << "\n";
        return;
    }
    if ((n-m)%2 != 0){
        cout << "NO" << "\n";
        return;
    }
    cout << "YES" << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}