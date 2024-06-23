#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long powersoftwo[200001];
long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2)%MOD;
    if (b % 2)
        return ((res * res)%MOD) * a;
    else
        return res * res;
}
void solve(){
    long long n,k; cin >> n >> k;
    long long dp[k+1];
    dp[0] = 1;
    for (int i = 1; i <= k; i++){
        if (n%2 == 1) {
            dp[i] = dp[i - 1] * (powersoftwo[n - 1]) + dp[i - 1];
            dp[i] %= MOD;
        } else{
            dp[i] = dp[i-1] * (powersoftwo[n-1]-1) + binpow(powersoftwo[i-1],n);
            dp[i] %= MOD;
        }
    }
    if (dp[k] < 0){
        dp[k] += MOD;
    }
    cout << dp[k] << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    powersoftwo[0] = 1;
    for (int i = 1; i < 200001; i++){
        powersoftwo[i] = powersoftwo[i-1]*2;
        powersoftwo[i] %= MOD;
    }
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}
