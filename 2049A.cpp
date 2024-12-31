#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i ++){
        cin >> arr[i];
    }
    bool streak = false;
    int answer = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] == 0 && streak){
            streak = false;
            answer += 1;
        } else if (arr[i] != 0){
            streak = true;
        }
    }
    if (streak){
        answer += 1;
    }
    if (answer == 1) {
        cout << answer << "\n";
    }
    else if (answer == 0){
        cout << answer << "\n";
    } else{
        cout << 2 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}
