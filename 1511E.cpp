#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
void solve() {

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; cin >> n >> m;
    long long powersoftwo[300001];
    powersoftwo[0] = 1;
    for (int i = 1; i <= 300000; i++){
        powersoftwo[i] = (powersoftwo[i-1]*2)%MOD;
    }
    long long dp[300001];
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 3;
    for (int i = 4; i <= 300000; i++){
        dp[i] = (powersoftwo[i-2] + 2*dp[i-2] + dp[i-1])%MOD;
    }
    int totalwhite = 0;
    char matrix[n][m];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >>matrix[i][j];
            if (matrix[i][j] == 'o'){
                totalwhite += 1;
            }
        }
    }
    int currstreak = 0;
    long long answer = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (matrix[i][j] == 'o'){
                currstreak += 1;
            } else{
                answer += dp[currstreak]*powersoftwo[totalwhite-currstreak];
                answer %= MOD;
                currstreak = 0;
            }
        }
        answer += dp[currstreak]*powersoftwo[totalwhite-currstreak];
        answer %= MOD;
        currstreak = 0;
    }
    for (int i = 0; i < m; i++){
        currstreak = 0;
        for (int j = 0; j < n; j++){
            if (matrix[j][i] == 'o'){
                currstreak += 1;
            } else{
                answer += dp[currstreak]*powersoftwo[totalwhite-currstreak];
                answer %= MOD;
                currstreak = 0;
            }
        }
        answer += dp[currstreak]*powersoftwo[totalwhite-currstreak];
        answer %= MOD;
        currstreak = 0;
    }
    cout << (answer+MOD)%MOD << "\n";

}
