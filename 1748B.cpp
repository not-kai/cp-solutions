#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        char temp; cin >> temp;
        arr[i] = temp - '0';
    }
    vector<set<int>> occurances(10);
    for (int i = 0; i < n; i++){
        occurances[arr[i]].insert(i);
    }
    vector<vector<int>> prefixsum(n, vector<int>(10));
    prefixsum[0][arr[0]] += 1;
    for (int i = 1; i < n; i++){
        for (int j = 0; j < 10; j++){
            if (j == arr[i]){
                prefixsum[i][j] = prefixsum[i-1][j]+1;
            } else{
                prefixsum[i][j] = prefixsum[i-1][j];
            }
        }
    }
    int answer = 0;
    for (int i = 0; i < n; i++){
        vector<int> currocc(10);
        int currunique = 0;
        int onindex = i;
        set<pair<int,int>> nearestocc;
        for (int j = 0; j < 10; j++){
            auto iter = occurances[j].lower_bound(i);
            if (iter != occurances[j].end()){
                nearestocc.insert({*iter, j});
            }
        }
        while (onindex < n){
            currocc[arr[onindex]] += 1;
            if (currocc[arr[onindex]] == 1){
                nearestocc.erase({onindex, arr[onindex]});
                currunique += 1;
            }
            bool flag = false;
            for (int j = 0; j < 10; j++){
                if (currocc[j] > currunique){
                    flag = true;
                }
            }
            if (!flag){
                answer += 1;
                onindex += 1;
            } else{
                if (nearestocc.empty()){
                    break;
                } else{
                    onindex = (*nearestocc.begin()).first;
                    for (int j = 0; j  < 10; j++){
                        if (i != 0) {
                            currocc[j] = prefixsum[onindex - 1][j] - prefixsum[i - 1][j];
                        } else{
                            currocc[j] = prefixsum[onindex -1][j];
                        }
                    }
                }
            }
        }
    }
    cout << answer << "\n";

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}
