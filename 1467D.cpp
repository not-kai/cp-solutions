#include <bits/stdc++.h>

typedef long long i1;
using namespace std;
#define MOD 1000000007
int main() {
    i1 n,k,q;
    cin >> n >> k >> q;
    i1 arr[n];
    i1 dp[n][k+1];
    i1 totalinstances[n];
    for (i1 i = 0; i < n; i++){
        cin >> arr[i];
    }
    memset(dp, 0, sizeof dp);
    for (i1 i = 0; i < n; i++) {
        dp[i][0] = 1;
    }
    for (i1 j = 0; j < k; j++){
        for (i1 i = 0; i < n; i++){
            if (i != 0){
                dp[i-1][j+1] += dp[i][j];
                dp[i-1][j+1] %= MOD;
            }
            if (i != n-1){
                dp[i+1][j+1] += dp[i][j];
                dp[i+1][j+1] %= MOD;
            }
        }
    }
    i1 answer = 0;
    for (i1 i = 0; i < n; i++){
        totalinstances[i] = 0;
            for (i1 j = 0; j <= k; j++) {totalinstances[i] += (dp[i][j]*dp[i][k-j])%MOD; totalinstances[i] %= MOD;}
    }
    for (i1 i = 0; i < n; i++){
        answer += (arr[i]*totalinstances[i])%MOD;
        answer %= MOD;
    }
    for (i1 i = 0; i < q; i++){
        i1 a,b; cin >> a >> b;
        a-=1;
        answer += ((b - arr[a])*totalinstances[a])%MOD;
        answer %= MOD;
        if (answer < 0){
            answer += MOD;
        }
        cout << answer << "\n";
        arr[a] = b;
    }
}
