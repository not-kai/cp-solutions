#include <bits/stdc++.h>

using namespace std;
struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second; // Min-heap based on the second value
    }
};
void solve() {
    int n; cin >> n;
    vector<char> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<pair<int,int>> restrictions(n); //first is must be to the left, right is must be to the right
    for (int i = 0; i < n; i++){
        restrictions[i] = {0, n-1};
    }
    for (int i = 0; i < n; i++){
        if (arr[i] == 's'){
            for (int j = 0; j < n-i; j++){
                restrictions[j].first = max(restrictions[j].first,i);
            }
        } else if (arr[i] == 'p'){
            for (int j = 0; j <= i; j++){
                restrictions[j].second = min(restrictions[j].second,i);
            }
        }
    }
    for (int i = 0; i < n; i++){
        if (restrictions[i].first > restrictions[i].second){
            cout << "NO" << "\n";
            return;
        }
    }
    priority_queue<pair<int,int>> pq;
    sort(restrictions.begin(), restrictions.end());
    int onindex = 0;
    for (int i = 0; i < n; i++){
        while (onindex != n && restrictions[onindex].first <= i){
            pq.push({-restrictions[onindex].second, restrictions[onindex].first});
            onindex += 1;
        }
        if (pq.empty()){
            continue;
        }
        auto t = pq.top(); pq.pop();
        if ((-t.first) < i){
            cout << "NO" << "\n";
            return;
        }
    }
    if (!pq.empty()){
        cout << "NO" << "\n";
        return;
    }
    cout << "YES" << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin >> t; for (int i = 0; i <t; i++){
        solve();
    }
}
