#include <bits/stdc++.h>
#define MOD 998244353
typedef long long i1;
using namespace std;
i1 n;
i1 arr[300];
i1 dp[300][90001];

i1 sansundertale(i1 pos, i1 number){
    if (pos < 1 || pos > n-2){
        return 1;
    }

    if (dp[pos][number] != -1){
        return dp[pos][number];
    }

    if (number == 0){
        dp[pos][number] = sansundertale(pos+1,arr[pos+1]);
        dp[pos][number] %= MOD;
        return dp[pos][number];
    } else{
        dp[pos][number] = sansundertale(pos+1, abs(arr[pos+1] + number)) + sansundertale(pos+1, abs(arr[pos+1]-number));
        dp[pos][number] %= MOD;
        return dp[pos][number];
    }


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    memset(dp, -1, sizeof dp);
    for (i1 i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << sansundertale(1,arr[1]);

}