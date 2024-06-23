#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
void solve() {
    int n,k; cin >> n >> k;
    vector<long long> arr(n);
    long long totalsum = 0;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        totalsum += arr[i];
    }
    int pointer1 = 0;
    int pointer2 = 0;
    long long maxwindow = 0;
    long long currwindow = 0;
    while (pointer2 < n) {
        if (currwindow >= 0) {
            currwindow += arr[pointer2];
            pointer2 += 1;
            maxwindow = max(maxwindow, currwindow);
        } else {
            currwindow -= arr[pointer1];
            pointer1 += 1;
            maxwindow = max(maxwindow, currwindow);
        }
    } maxwindow %= MOD;
    totalsum %= MOD;
    while (totalsum < 0){
        totalsum += MOD;
    }
    if (maxwindow == 0){
        cout << totalsum << "\n";
        return;
    }
    long long currentk = 1;
    for (int i = 0; i < k; i++){
        totalsum += (maxwindow*currentk)%MOD;
        totalsum %= MOD;
        currentk *= 2;
        currentk%=MOD;
    }
    while (totalsum < 0){
        totalsum += MOD;
    }
    cout << totalsum << "\n";



}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}