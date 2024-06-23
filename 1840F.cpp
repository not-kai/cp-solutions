#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,m, r;
    cin >> n >> m >> r;
    unordered_map<int, pair<unordered_set<int>, unordered_set<int>>> railguns;
    for (int i = 0; i < r; i++) {
        int time, coord, which;
        cin >> time >> which >> coord;
        if (time > n+m+r){
            continue;
        }
        if (which == 1) {
            railguns[time].first.insert(coord);
        } else {
            railguns[time].second.insert(coord);
        }
    }
    int dp[n+1][m+1][r+1];
    memset(dp,  -1,sizeof dp);
    for (int i = 0; i < r+1; i++){
        if ((railguns[i+n+m].first.find(n) != railguns[i+n+m].first.end()) || (railguns[i+n+m].second.find(m) != railguns[i+n+m].second.end())){dp[n][m][i] = INT_MAX;} else{
        dp[n][m][i] = i;}
    }
    for (int sum = n+m-1; sum >= 0; sum -= 1){
        if (sum > n){
            for (int tempx = n; sum-tempx <= m; tempx -= 1){
                if (tempx < 0){
                    break;
                }
                for (int delay = r; delay >= 0; delay -= 1){
                    if ((railguns[delay + sum].first.find(tempx) != railguns[delay+sum].first.end()) || (railguns[delay + sum].second.find(sum-tempx) != railguns[delay+sum].second.end())){
                        dp[tempx][sum-tempx][delay] = INT_MAX;
                        //cout << tempx << " " << sum-tempx << " " << delay << " skipped" << endl;
                        continue;
                    }
                    int currentvalue = INT_MAX;
                    if (delay != r){
                        currentvalue = min(currentvalue, dp[tempx][sum-tempx][delay+1]);
                    }
                    if (tempx != n){
                        currentvalue = min(currentvalue, dp[tempx+1][sum-tempx][delay]);
                    }
                    if (sum-tempx != m){
                        currentvalue = min(currentvalue, dp[tempx][sum-tempx+1][delay]);
                    }
                    dp[tempx][sum-tempx][delay] = currentvalue;
                }
            }
        } else{
            for (int tempx = sum; sum-tempx <= m; tempx -= 1){
                if (tempx < 0){
                    break;
                }
                for (int delay = r; delay >= 0; delay -= 1) {
                    if ((railguns[delay + sum].first.find(tempx) != railguns[delay + sum].first.end()) || (railguns[delay + sum].second.find(sum - tempx) != railguns[delay + sum].second.end())) {
                        dp[tempx][sum - tempx][delay] = INT_MAX;
                        //cout << tempx << " " << sum-tempx << " " << delay << " skipped" << endl;
                        continue;
                    }
                    int currentvalue = INT_MAX;
                    if (delay != r){
                        currentvalue = min(currentvalue, dp[tempx][sum-tempx][delay+1]);
                    }
                    /*
                    if (sum == 0 && delay == 0){
                        cout << currentvalue << endl;
                    }
                     */
                    if (tempx != n){
                        currentvalue = min(currentvalue, dp[tempx+1][sum-tempx][delay]);
                    }
                    /*
                    if (sum == 0 && delay == 0){
                        cout << currentvalue << endl;
                    }
                     */
                    if (sum-tempx != m){
                        currentvalue = min(currentvalue, dp[tempx][sum-tempx+1][delay]);
                    }
                    /*
                    if (sum == 0 && delay == 0){
                        cout << currentvalue << endl;
                    }
                     */
                    dp[tempx][sum-tempx][delay] = currentvalue;
                }

            }
        }
    }
    if (dp[0][0][0] == INT_MAX){
        cout << -1 << "\n";
    } else {
        cout << dp[0][0][0] + n + m << "\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int testcases;
    cin >> testcases;
    for (int i = 0; i < testcases; i++){
        solve();
    }
}
