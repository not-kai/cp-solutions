#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n, m; cin >> n >> m;
    int k; cin >> k;
    int x, y;
    cin >> x >> y;
    vector<pair<int,int>> friends(k);
    for (int i = 0; i < k; i++){
        cin >> friends[i].first >> friends[i].second;
    }
    for (int i = 0; i < k; i++){
        if (abs(friends[i].first + friends[i].second - x - y) % 2 == 0){
            cout << "NO" << "\n";
            return;
        }
    }
    cout << "YES" << "\n";
    /*
    if (k >= 3){
        cout << "NO" << "\n";
    } else{
        if (k == 1) {
            if (abs(friends[0].first - x + friends[0].second - y) % 2 == 0) {
                cout << "NO" << "\n";
            } else{
                cout << "YES" << "\n";
            }
        }
        if (k == 2){
            if (abs(friends[0].first - x + friends[0].second - y) % 2 == 0) {
                cout << "NO" << "\n";
            } else if (abs(friends[1].first - x + friends[1].second - y) % 2 == 0) {
                cout << "NO" << "\n";
            }
            else{
                cout << "YES" << "\n";
            }
        }
    }
     */

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    for (int i = 0; i < t; i++){
        solve();
    }
}
