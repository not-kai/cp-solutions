#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n,k; cin >> n >> k;
    vector<int> arr(n);
    int total = 0;
    for (int i = 0; i < n; i++){
       cin >> arr[i];
       arr[i] += total;
    }
    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());
    int currcount = 0;
    int minanswer = INT_MAX;
    for (int i = 0; i < n; i++){
        currcount += arr[i];
        if (currcount > k){
            break;
        }
        minanswer = min(minanswer, k - currcount);
    }
    cout << minanswer << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}