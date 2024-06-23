#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0 ; i < n; i++){
        cin >> arr[i];
    }
    int minanswer = 1;
    for (int i = 0; i < 20; i++){
        vector<int> positions;
        positions.push_back(-1);
        for (int j = 0; j < n; j++){
            if ((arr[j]>>i)&1){
                positions.push_back(j);
            }
        }
        positions.push_back(n);
        if (positions.size() == 2){
            continue;
        }
        for (int j = 0; j < positions.size()-1; j++){
            minanswer = max(minanswer, positions[j+1] - positions[j]);
        }
    }
    cout << minanswer << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}