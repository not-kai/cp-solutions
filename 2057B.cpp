#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    int k; cin >> k;

    vector<int> arr(n);
    map<int,int> occurances;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        occurances[arr[i]] += 1;
    }
    vector<pair<int,int>> grr;
    for (auto i : occurances){
        grr.push_back({i.second, i.first});
    }
    sort(grr.begin(), grr.end());
    int answer = grr.size();
    for (int i =0; i < grr.size(); i++){
        if (k >= grr[i].first){
            k -= grr[i].first;
            answer -= 1;
        } else{
            break;
        }
        if (k == 0){
            break;
        }
    }
    cout << max(1,answer) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}