#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    map<int,int> occurances;
    unordered_map<int,int> starting;
    for (int i = 0; i < n; i++){
        occurances[arr[i]] += 1;
    }
    int prefix = n;
    for (auto i = occurances.begin(); i != occurances.end(); i++){
        starting[i->first] = prefix;
        prefix -= i->second;
    }
    vector<int> permunation(n);
    for (int i = 0; i < n; i++){
        permunation[i] = starting[arr[i]];
        starting[arr[i]] -= 1;
    }
    for (int i = 0; i < n; i++){
        cout << permunation[i] << " ";
    }
    cout << "\n";

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}
