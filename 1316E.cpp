#include <bits/stdc++.h>

typedef long long i1;
using namespace std;
int main() {
    i1 n,p,k; cin >> n >> p >> k;
    vector<pair<i1, vector<i1>>> audience(n, {0,{}});
    for (i1 i = 0; i < n; i++){
        cin >> audience[i].first;
    }
    for (i1 i = 0; i < n; i++){
        for (i1 j = 0; j < p; j++){
            i1 temp; cin >> temp; audience[i].second.push_back(temp);
        }
    }
    sort(audience.rbegin(), audience.rend());
    i1 weirdassdpthing[(1<<p)][n+1];
    for (i1 i = 0; i <= n; i++){
        for (i1 j = 0; j < (1<<p); j++){
            weirdassdpthing[j][i] = INT_MIN;
        }
    }
    weirdassdpthing[0][0] = 0;
    for (i1 j = 0; j < n; j++){
        for (i1 i = 0; i < (1 << p); i++){
            if (weirdassdpthing[i][j] == INT_MIN){
                continue;
            }
            i1 numberofsetbits = 0;
            for (i1 l = 0; l < p; l++){
                if ((1<<l) & i){
                    numberofsetbits += 1;
                } else{
                    weirdassdpthing[i + (1<<l)][j+1] = max(weirdassdpthing[i + (1 << l)][j+1], weirdassdpthing[i][j] + audience[j].second[l]);
                }
            }
            if (k + numberofsetbits > j){
                weirdassdpthing[i][j+1] = max(weirdassdpthing[i][j+1], weirdassdpthing[i][j] + audience[j].first);
            } else{
                weirdassdpthing[i][j+1] = max(weirdassdpthing[i][j+1], weirdassdpthing[i][j]);
            }
        }
    }
    cout << weirdassdpthing[(1<<p)-1][n];
}
