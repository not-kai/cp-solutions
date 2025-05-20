#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<pair<long long, long long>> points(n);
    unordered_map<long long, int> perx;
    unordered_map<long long, bool> propogation;
    for (int i = 0; i < n; i++){
        cin >> points[i].first >> points[i].second;
        perx[points[i].first] += 1;
        propogation[points[i].first + points[i].second] = !(propogation[points[i].first + points[i].second]);
    }
    long long x;
    for (auto i : perx){
        if (i.second%2==1){
            x = i.first;
            break;
        }
    }
    long long xy;
    for (auto i : propogation){
        if (i.second){
            xy = i.first;
            break;
        }
    }
    cout << x << " " << xy-x << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}
