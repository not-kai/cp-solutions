#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n,m; cin >> n >> m;
    cout << max(n+1,m+1) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}