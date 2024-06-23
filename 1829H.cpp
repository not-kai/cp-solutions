#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int bitmaskdp[200000][64];
int main() {
    int testcases;
    cin >> testcases;
    for (int t = 0; t < testcases; t++){
        int n,k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < 64; j++){
                bitmaskdp[i][j] = 0;
            }
        }
        bitmaskdp[0][arr[0]] = 1;
        for (int i = 1; i < n; i++){
            bitmaskdp[i][arr[i]] %= MOD;
            bitmaskdp[i][arr[i]] += 1;
            bitmaskdp[i][arr[i]] %= MOD;
            for (int j = 0; j < 64; j++){
                bitmaskdp[i][j] = ((bitmaskdp[i][j] % MOD) + (bitmaskdp[i-1][j] % MOD))%MOD;
                bitmaskdp[i][j & arr[i]] = ((bitmaskdp[i][j & arr[i]] % MOD) + (bitmaskdp[i-1][j] % MOD))%MOD;
            }
        }
        int answer = 0;
        for (int i = 0; i < 64; i++){
            int bits = 0;
            for (int j = 0; j < 6; j++){
                if (i >> j & 1){
                    bits += 1;
                }
            }
            if (bits == k){
                answer %= MOD;
                answer += bitmaskdp[n-1][i] % MOD;
                answer %= MOD;
            }
        }
        if (answer < 0){
            answer += MOD;
        }
        cout << answer << "\n";
    }
}
