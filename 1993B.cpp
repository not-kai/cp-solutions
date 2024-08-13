#include <bits/stdc++.h>

typedef long long i1;
using namespace std;

void solve() {
    set<i1> odd; vector<i1> even; i1 n; cin >> n; for (i1 i = 0; i < n; i++){
        i1 temp; cin >> temp;
        if (temp%2 == 0){
            even.push_back(temp);
        } else{
            odd.insert(temp);
        }
    }
    if (odd.size() == n || even.size() == n){
        cout << 0 << "\n"; return;
    }
    i1 ans = 0;
    sort(even.begin(), even.end());
    for (i1 i = 0 ; i < even.size(); i++){
        if (*odd.rbegin() > even[i]){
            ans += 1;
            odd.insert(even[i] + *(odd.rbegin()));
        } else{
            odd.insert((*odd.rbegin()) + even[even.size()-1]);
            ans += 1;
            i -= 1;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i1 t; cin >> t; for (i1 i = 0; i < t; i++){
        solve();
    }
}
