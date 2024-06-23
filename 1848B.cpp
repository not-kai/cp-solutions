#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    unordered_map<int, pair<int,int>> maxdistance;
    unordered_map<int, int> lastseen;
    for (int i = 0; i <= k; i++){
        lastseen[i] = -1;
    }
    for (int i = 0; i < n; i++){
        if (lastseen[arr[i]] != -1){
            maxdistance[arr[i]].second = max(maxdistance[arr[i]].second, i - lastseen[arr[i]]- 1);
            lastseen[arr[i]] = i;
            if (maxdistance[arr[i]].second > maxdistance[arr[i]].first){
                swap(maxdistance[arr[i]].second, maxdistance[arr[i]].first);
            }
        } else {
            lastseen[arr[i]] = i;
            maxdistance[arr[i]].second = max(maxdistance[arr[i]].second, i);
            if (maxdistance[arr[i]].second > maxdistance[arr[i]].first){
                swap(maxdistance[arr[i]].second, maxdistance[arr[i]].first);
            }
        }
    }
    for (int i = 1; i <= k; i++){
        maxdistance[i].second = max(maxdistance[i].second, n - lastseen[i]-1);
        if (maxdistance[i].second > maxdistance[i].first){
            swap(maxdistance[i].second, maxdistance[i].first);
        }
    }
    int answer = INT_MAX;
    for (int i = 1; i <= k; i++){

        int temp = max(maxdistance[i].first/2, maxdistance[i].second);
        answer = min(answer, temp);
    }
    cout << answer << "\n";
    /*
    int dp[n+1][k+1][2];
    memset(dp, -1, sizeof dp);
    dp[0][0][0] = 0;
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= k; j++){
            if (dp[i][j][0] == -1){
                continue;
            }

        }
    }
     */
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0; i  < t; i++){
        solve();
    }
}
