#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n; cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int startingindex = n/2;
    if (n%2 == 0){
        startingindex -= 1;
    }
    long long value = arr[startingindex];
    int change = 1;
    while (startingindex < n-1){
        startingindex += 1;
        if (arr[startingindex] != value){
            break;
        } else{
            change += 1;
        }
    }
    cout << change << "\n";

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}