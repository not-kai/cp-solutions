#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n; cin >> n;
    int mindifference = INT_MAX;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i < n; i++){
        if (arr[i] < arr[i-1]){
            cout << 0 << "\n"; return;
        }
        mindifference = min(mindifference, arr[i]-arr[i-1]);
    }
    cout << (mindifference/2) + 1 << "\n";
}
int main() {
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}
