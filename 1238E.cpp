#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; cin >> n >> m;
    vector<int> password(n);
    int pairs[m][m];
    memset(pairs, 0, sizeof pairs);
    for (int i = 0 ; i < n; i++){
        char temp; cin >> temp; password[i] = temp - 'a';
        if (i != 0){
            pairs[min(password[i],password[i-1])][max(password[i],password[i-1])] += 1;
        }
    }
    int extend[1<<m];
    for (int i = 0; i < (1<<m); i++){
        bool valid[m];
        memset(valid, 0, sizeof valid);
        for (int j = 0; j < m; j++){
            if ((i>>j) & 1){
                valid[j] = true;
            }
        }
        extend[i] = 0;
        for (int a = 0; a < m; a++){
            for (int b = a+1; b < m; b++){
                if (valid[b] && valid[a]){
                    continue;
                } if (valid[b] || valid[a]){
                    extend[i] += pairs[a][b];
                }
            }
        }
    }
    int dp[1 << m];
    dp[0] = 0;
    for (int i = 1; i < (1<<m); i++){
        int minans = INT_MAX;
        for (int j = 0; j < m; j++){
            if ((i>>j) & 1){
                minans = min(minans,dp[i ^ (1<<j)] + extend[i ^ (1<<j)]);
            }
        }
        dp[i] = minans;
    }
    cout << dp[(1<<m)-1] << "\n";
}
