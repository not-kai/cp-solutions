#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n,c,k; cin >> n >> c >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        char temp; cin >> temp;
        arr[i] = temp - 'A';
    }
    vector<int> badmask;
    vector<int> sums(c);
    for (int i = 0; i < c; i++){
        sums[i] = 0;
    }
    for (int i = 0; i < k; i++){
        sums[arr[i]] += 1;
    }
    vector<bool> ors(c);
    for (int i = 0; i < c; i++){
        if (sums[i]){
            ors[i] = true;
        } else{
            ors[i] = false;
        }
    }
    int geometrydash = 0;
    for (int i = 0; i < c; i++){
        geometrydash += (ors[i] << i);
    }
    badmask.push_back(geometrydash);
    for (int i = k; i < n; i++){
        sums[arr[i-k]] -= 1;
        sums[arr[i]] += 1;
        vector<bool> temp(c);
        for (int j = 0; j < c; j++){
            if (sums[j]){
                ors[j] = true;
            } else{
                ors[j] = false;
            }
        }
        geometrydash = 0;
        for (int j = 0; j < c; j++){
            geometrydash += (ors[j] << j);
        }
        badmask.push_back(geometrydash);
    }
    for (int i = n-k; i < n-1; i++){
        sums[arr[i]] -= 1;
        vector<bool> temp(c);
        for (int j = 0; j < c; j++){
            if (sums[j]){
                ors[j] = true;
            } else{
                ors[j] = false;
            }
        }
        geometrydash = 0;
        for (int j = 0; j < c; j++){
            geometrydash += (ors[j] << j);
        }
        badmask.push_back(geometrydash);
    }
    bool dp[1 << c];
    memset(dp, 0, sizeof dp);
    for (int i : badmask){
        dp[((1 << c)-1)^i] = true;
    }
    for (int i = (1<<c)-1; i >= 0; i -= 1){
        for (int j = 0; j < c; j++){
            dp[i] = dp[i] | dp[i|(1<<j)];
        }
    }
    int minanswer = c;
    for (int i = 0; i < (1<<c); i++){
        if (!dp[i]){
            minanswer= min(minanswer,__builtin_popcount(i));
        }
    }
    cout << minanswer << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}
