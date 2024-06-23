#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,m; cin >> n >> m;
    int originalstring[n];
    for (int i = 0; i < n; i++){
        char temp;
        cin >> temp;
        originalstring[i] = temp - 'a';
    }
    int newstring[m];
    for (int i = 0; i < m; i++){
        char temp;
        cin >> temp;
        newstring[i] = temp - 'a';
    }
    unordered_map<int, set<int>> locations;
    for (int i = 0; i < n; i++){
        locations[originalstring[i]].insert(i);
    }
    for (int i = 0; i < m; i++){
        if (locations[newstring[i]].empty()){
            cout << "NO" << "\n";
            return;
        }
        int firstloc = *locations[newstring[i]].begin();
        for (int j = 0; j < newstring[i]; j++){
            locations[j].erase(locations[j].begin(), locations[j].upper_bound(firstloc));
        }
        locations[newstring[i]].erase(firstloc);
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