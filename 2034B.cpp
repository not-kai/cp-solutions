#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n,m,k; cin >> n >> m >> k;
    vector<bool> arr(n);
    for (int i = 0; i < n; i++){
        char temp; cin >> temp;
        arr[i] = (temp == '1');
    }
    int currstreak = 0;
    int currstrength = 0;
    int answer = 0;
    for (int i = 0; i < n; i++){
        if (currstrength > 0){
            currstrength -= 1;
            continue;
        }
        if (arr[i] == 0){
            currstreak += 1;
        } else{
            currstreak = 0;
        }
        if (currstreak >= m){
            currstreak = 0;
            answer += 1;
            currstrength = k-1;
        }
    }
    cout << answer << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0; i < t; i++) {
      solve();
    }
}