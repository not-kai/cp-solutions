#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    unordered_map<int,int> instances;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        instances[arr[i]] += 1;
    }
    sort(arr.begin(), arr.end());
    if (instances[*arr.rbegin()]==n){
        cout << -1 << "\n";
    } else{
        cout << n-(instances[*arr.rbegin()]) << " " << instances[*arr.rbegin()] << "\n";
        for (int i = 0; arr[i] != *arr.rbegin(); i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < instances[*arr.rbegin()]; i++){
            cout << *arr.rbegin() << " ";
        }
        cout << "\n";
    }

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}
