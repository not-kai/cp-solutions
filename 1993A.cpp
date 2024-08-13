#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n; cin >> n;
    vector<int> charvalues(5);
    for (int i = 0; i < 4*n; i++){
        char temp; cin >> temp;
        if (temp == '?'){
            charvalues[4] += 1;
        } else{
            charvalues[temp - 'A'] += 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < 4; i++){
        ans += min(n, charvalues[i]);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}
