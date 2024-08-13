#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    vector<int> brr(n);
    for (int i =0 ; i< n; i++){
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++){
        cin >> brr[i];
    }
    if (arr == brr){
        cout << "Bob" << "\n";
        return;
    }
    reverse(brr.begin(), brr.end());
    if (arr == brr){
        cout << "Bob" << "\n";
        return;
    }
    cout << "Alice" << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0 ;i < t; i++){
        solve();
    }
}
