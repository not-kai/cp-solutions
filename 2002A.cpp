#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n,m,k; cin >> n >> m >> k;
    cout << min(n,k) * min(m,k) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}
