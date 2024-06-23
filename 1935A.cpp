#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    string grr; cin >> grr;
    vector<string> rah;
    rah.push_back(grr);
    string jojo = grr;
    reverse(grr.begin(), grr.end());
    rah.push_back(grr + jojo);
    sort(rah.begin(), rah.end());
    cout << rah[0] << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0 ; i< t; i++){
        solve();
    }
}