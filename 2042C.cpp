#include <bits/stdc++.h>

typedef long long i1;
using namespace std;

void solve() {
    i1 n,k; cin >> n >> k;
    vector<i1> arr(n);
    for (i1 i = 0; i < n; i++){
        char temp; cin >> temp;
        if (temp == '0'){
            arr[i] = -1;
        } else{
            arr[i] = 1;
        }
    }
    vector<i1> suffix(n);
    suffix[n-1] = arr[n-1];
    for (i1 i = n-2; i >= 0; i--){
        suffix[i] = suffix[i+1] + arr[i];
        if (i == 0){
            suffix[i] = -1000000000000000;
        }
    }
    i1 answer = 0;
    i1 currsum = 0;
    sort(suffix.begin(), suffix.end());
    for (i1 i = n-1; i >= 0; i--){
        if (suffix[i] < 0){
            cout << -1 << "\n";
            return;
        }
        answer += 1;
        currsum += suffix[i];
        if (currsum >= k){
            cout << answer+1 << "\n";
            return;
        }

    }
    cout << -1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i1 t; cin >> t; for (i1 i = 0; i < t; i++){
        solve();
    }
}