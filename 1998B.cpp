#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i =0; i < n; i++){
        cin >> arr[i];
    }
    for (int i = 1; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << arr[0] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0; i < t; i++){solve();}
}