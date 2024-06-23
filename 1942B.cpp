#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n ;i++){
        cin >> arr[i];
    }
    set<int> numbers;
    for (int i = 0; i < n; i++){
        numbers.insert(i);
    }
    vector<int> permunation(n);
    for (int i = 0; i < n; i++){
        int mex = *numbers.begin();
        if (numbers.find(mex - arr[i]) != numbers.end()){
            permunation[i] = mex - arr[i];
            numbers.erase(mex-arr[i]);
        } else{
            permunation[i] = mex;
            numbers.erase(mex);
        }
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