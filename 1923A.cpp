#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    int totalones = 0;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        if (arr[i] == 1){
            totalones += 1;
        }
    }
    int answer = 0;
    bool reachedoneyet = false;
    for (int i = 0; i < n; i++){
        if (totalones == 0){
            break;
        }
        if (arr[i] == 1){
            if (reachedoneyet){
                totalones -= 1;
            } else{
                reachedoneyet = true;
                totalones -= 1;
            }
        } else{
            if (reachedoneyet){
                answer += 1;
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