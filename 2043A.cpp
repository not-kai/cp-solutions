#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long coin; cin >> coin;
    long long coins = 1;
    while (coin >= 4){
        coin /= 4;
        coins *= 2;
    }
    cout << coins << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}
