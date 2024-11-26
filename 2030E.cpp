#include <bits/stdc++.h>

using namespace std;
#define MAXN 200000
#define MOD 998244353
namespace CombinationMod{
    long long fac[MAXN + 1];
    long long inv[MAXN + 1];
    long long exp(long long x, long long n, long long m) {
        x %= m;  // note: m * m must be less than 2^63 to avoid ll overflow
        long long res = 1;
        while (n > 0) {
            if (n % 2 == 1) { res = res * x % m; }
            x = x * x % m;
            n /= 2;
        }
        return res;
    }
    void factorial(long long p) {
        fac[0] = 1;
        for (int i = 1; i <= MAXN; i++) { fac[i] = fac[i - 1] * i % p; }
    }
    void inverses(long long p) {
        inv[MAXN] = exp(fac[MAXN], p - 2, p);
        for (int i = MAXN; i >= 1; i--) { inv[i - 1] = inv[i] * i % p; }
    }
    long long choose(long long n, long long r, long long p) {
        if (n < r){
            return 0;
        }
        return fac[n] * inv[r] % p * inv[n - r] % p;
    }
} //O(n+log(MOD), also has binary exponentiation with modulo in O(log(n))
void solve() {
    int n; cin >> n;
    map<int,int> count;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        count[arr[i]] += 1;
    }
    vector<vector<long long>> dp(n);
    vector<vector<long long>> prefix(n);
    vector<int> sizes(n);
    int currmax = count[0];
    for (int i = 0; i < n; i++){
        currmax = min(currmax, count[i]);
        sizes[i] = currmax;
        dp[i].resize(currmax+1);
        prefix[i].resize(currmax+1);
        vector<long long> waystogetprefix(count[i]+1);
        for (int j = 0; j <= count[i]; j++){
            waystogetprefix[j] = CombinationMod::choose(count[i], j, MOD);
            if (j != 0){
                waystogetprefix[j] += waystogetprefix[j-1];
                waystogetprefix[j] %= MOD;
            }
        }
        for (int j = 0; j <= currmax; j++){
            if (i != 0) {
                dp[i][j] = 0;
                if (j == 0) {
                    dp[i][j] += waystogetprefix[0] * prefix[i - 1][0];
                    dp[i][j] %= MOD;
                } else {

                    dp[i][j] += (waystogetprefix[j] - waystogetprefix[j - 1]) * prefix[i - 1][j];
                    dp[i][j] %= MOD;
                    dp[i][j] += dp[i - 1][j] * (waystogetprefix[count[i]] - waystogetprefix[j - 1]);
                    dp[i][j] %= MOD;
                    dp[i][j] -= dp[i - 1][j] * (waystogetprefix[j] - waystogetprefix[j - 1]);
                    dp[i][j] %= MOD;
                }
            } else{
                if (j == 0){
                    dp[i][j] = 1;
                } else{
                    dp[i][j] = waystogetprefix[j] - waystogetprefix[j-1];
                }
            }
        }
        prefix[i][currmax] = dp[i][currmax];
        for (int j = currmax-1; j >= 0; j--){
            prefix[i][j] = prefix[i][j+1] + dp[i][j];
            prefix[i][j] %= MOD;
        }
    }
    vector<long long> trueprefix(n+1);
    trueprefix[n] = 0;
    for (int i = n-1; i >= 0; i--){
        trueprefix[i] = trueprefix[i+1] + count[i];
    }
    long long answer = 0;
    for (int i = 0; i < n; i++){
        for (int j = 1; j <= sizes[i]; j++){
            answer += ((j * dp[i][j])%MOD) * CombinationMod::exp(2,trueprefix[i+1],MOD);
            answer %= MOD;
        }
    }
    cout << (answer+MOD)%MOD << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    CombinationMod::factorial(MOD);
    CombinationMod::inverses(MOD);
    for (int i = 0; i < t; i++) {
        solve();
    }
}
