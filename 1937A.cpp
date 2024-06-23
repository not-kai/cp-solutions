#include <bits/stdc++.h>
using namespace std;
vector<long long> powersoftwo;
void solve() {
    int n; cin >> n;
    auto i = upper_bound(powersoftwo.begin(), powersoftwo.end(), n);
    cout << *(prev(i)) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long curr = 1;
    while (curr <= 1000000000){
        powersoftwo.push_back(curr);
        curr *= 2;
    }
    int t; cin >> t; for (int i =0 ; i <t; i++){
        solve();
    }

}