#include <bits/stdc++.h>
using namespace std;
void solve() {
    int a,b; cin >> a >> b;
    cout << max(ceil(b*1.0/2.0),ceil((a+4*b)*1.0/15.0)) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i =0 ; i < t; i++){
        solve();
    }
}