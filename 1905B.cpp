#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<vector<int>> tree(n+1);
    for (int i = 0; i < n-1; i++){
        int a,b; cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    if (n == 1){
        cout << 0 << "\n";
    }
    int children = 0;
    for (int i = 1; i <= n; i++){
        if (tree[i].size() == 1){
            children += 1;
        }
    }
    int ans = 0;
    while (children > 3){
        children -= 2;
        ans += 1;
    }
    if (children == 3){
        ans += 2;
    } if (children == 2){
        ans += 1;
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