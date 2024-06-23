#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long i1;
long dp[201][1001][201]; //index, imbalance, open groups
int main() {
    i1 n, k;
    cin >> n >> k;
    vector<i1> arr(n+1);
    arr[0] = 0;
    for (i1 i = 1; i <= n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= k; j++){
            for (int l = 0; l <= n; l++){
                dp[i][j][l] = 0;
            }
        }
    }
    dp[0][0][0] = 1;
    for (i1 i = 0; i < n; i++){
        for (i1 j = 0; j <= k; j++){
            for (i1 l = 0; l <= n; l++){
                if (dp[i][j][l] == 0){
                    continue;
                }
                if (j+l*(arr[i+1]-arr[i]) > k){
                    continue;
                }
                //individual group + add on to one of l groups
                dp[i + 1][j+l*(arr[i+1]-arr[i])][l] += ((l+1)*dp[i][j][l])%MOD;
                dp[i + 1][j+l*(arr[i+1]-arr[i])][l] %= MOD;


                //make new group
                dp[i+1][j+l*(arr[i+1]-arr[i])][l+1] += (dp[i][j][l])%MOD;
                dp[i + 1][j+l*(arr[i+1]-arr[i])][l+1] %= MOD;

                //finish a group
                if (l > 0){
                    dp[i+1][j+l*(arr[i+1]-arr[i])][l-1] += (l*dp[i][j][l])%MOD;
                    dp[i + 1][j+l*(arr[i+1]-arr[i])][l-1] %= MOD;
                }


            }
        }
    }
    i1 answer = 0;
    for (i1 i = 0; i <= k; i++){
        answer += dp[n][i][0];
        answer %= MOD;
    }
    if (answer < 0){
        answer += MOD;
    }
    cout << answer;
}
