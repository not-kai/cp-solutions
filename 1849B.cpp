#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,k;cin >> n >> k;
    vector<int> arr(n);
    unordered_set<int> values;
    unordered_map<int, vector<int>> indexes;
    for (int i = 0; i <n; i++){
        cin >> arr[i];
        arr[i] %= k;
        if (arr[i] == 0){
            arr[i] = k;
        }
        values.insert(arr[i]);
        indexes[arr[i]].push_back(i);
    }
    vector<int> arr2;
    for (int i : values){
        arr2.push_back(i);
    }
    sort(arr2.begin(), arr2.end());
    for (int i = arr2.size()-1; i >= 0; i--){
        for (int j : indexes[arr2[i]]){
            cout << j+1 << " ";
        }
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
