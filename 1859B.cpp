#include <bits/stdc++.h>

typedef long long i1;
using namespace std;
void solve(){
    int n; cin >> n;
    vector<vector<i1>> arrays(n);
    for (int i = 0; i < n; i++){
        i1 temp; cin >> temp;
        for (i1 j = 0; j < temp; j++) {
            i1 value;
            cin >> value;
            arrays[i].push_back(value);
        }
        sort(arrays[i].begin(), arrays[i].end());
    }
    i1 minimumfirstvalue= INT_MAX;
    i1 minimumsecondvalue = INT_MAX;
    i1 totalsum = 0;
    for (int i = 0; i < n; i++){
        minimumfirstvalue = min(minimumfirstvalue, arrays[i][0]);
        minimumsecondvalue = min(minimumsecondvalue, arrays[i][1]);
        totalsum += arrays[i][1];
    }
    totalsum -= (minimumsecondvalue-minimumfirstvalue);
    cout << totalsum << "\n";



}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i1 t; cin >> t; for (i1 i = 0; i < t; i++){
        solve();
    }
}
