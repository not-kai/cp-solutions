#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353

typedef long long i1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i1 n; cin >> n;
    vector<i1> arr(n);
    for (i1 i = 0; i < n; i++){
        char temp; cin >> temp;
        if (temp == '-'){
            arr[i] = -1;
        } else{
            cin >> arr[i];
        }
    }
    i1 answer = 0;
    for (i1 i = 0; i < n; i++){
        if (arr[i] == -1){
            continue;
        }
        i1 dp[n][n+1];
        memset(dp, 0, sizeof dp);

        if (arr[0] == -1){
            dp[0][0] = 2;
        } else if (arr[0] == arr[i] && i > 0){
            dp[0][0] = 2;
        } else if (arr[0] > arr[i]){
            dp[0][0] = 2;
        } else{
            if (i == 0){
                dp[0][1] = 1;
            } else{
                dp[0][1] = 1;
                dp[0][0] = 1;
            }
        }
        for (i1 j = 1; j < n; j++) {
            if (arr[j] == -1) {
                for (i1 k = 0; k <= n; k++) {
                    dp[j][k] += dp[j - 1][k];
                    dp[j][k] %= MOD;
                }
                dp[j][0] += dp[j-1][0];
                dp[j][0] %= MOD;
                for (i1 k = 0; k < n; k++) {
                    dp[j][k] += dp[j - 1][k + 1];
                    dp[j][k] %= MOD;
                }
            } else if (arr[j] == arr[i] && i > j) {
                for (i1 k = 0; k <= n; k++) {
                    dp[j][k] += 2 * dp[j - 1][k];
                    dp[j][k] %= MOD;
                }
            } else if (arr[j] > arr[i]) {
                for (i1 k = 0; k <= n; k++) {
                    dp[j][k] += 2 * dp[j - 1][k];
                    dp[j][k] %= MOD;
                }
            } else {
                if (i == j) {
                    for (i1 k = 1; k <= n; k++) {
                        dp[j][k] += dp[j - 1][k - 1];
                        dp[j][k] %= MOD;
                    }
                } else {
                    for (i1 k = 0; k <= n; k++) {
                        dp[j][k] += dp[j - 1][k];
                        dp[j][k] %= MOD;
                    }
                    for (i1 k = 1; k <= n; k++) {
                        dp[j][k] += dp[j - 1][k - 1];
                        dp[j][k] %= MOD;
                    }
                    if (j > i){
                        dp[j][1] -= dp[j-1][0];
                    }
                }
            }
        }
        for (i1 j = 1; j <= n; j++){
            answer += arr[i]*dp[n-1][j];
            answer %= MOD;
        }
    }
    cout << answer << "\n";
}
