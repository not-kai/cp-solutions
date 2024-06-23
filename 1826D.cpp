#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    vector<int> arr;
    cin >> n;
    for (int i = 0; i < n; i++){
        int temp; cin >> temp; arr.push_back(temp);
    }
    vector<vector<int>> dp(n, vector<int>(3));
    dp[0][0] = arr[0];
    for (int i = 1; i < n; i++){
        dp[i][0] = max(dp[i-1][0], arr[i]+i);
    }
    dp[0][1] = 0;
    dp[1][1] = arr[0]+arr[1];
    for (int i = 2; i < n; i++){
        dp[i][1] = dp[i-1][1];
        dp[i][1] = max(arr[i] + dp[i-1][0], dp[i][1]);
    }
    dp[0][2] = 0;
    dp[1][2] = 0;
    dp[2][2] = arr[0] + arr[1] + arr[2] - 2;
    for (int i = 3; i < n; i++){
        dp[i][2] = dp[i-1][2];
        dp[i][2] = max(dp[i][2], arr[i] + dp[i-1][1] - i);
    }
    cout << dp[n-1][2] << "\n";
}
int main() {
    int testcases; cin >> testcases;
    for (int i = 0; i < testcases; i++){
        solve();
    }
}
