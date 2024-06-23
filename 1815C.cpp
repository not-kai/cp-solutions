#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,m; cin >> n >> m;
    vector<pair<int,int>> edges;
    for (int i = 0; i < m; i++){
        int a,b; cin >> a >> b;
        edges.push_back({a,b});
    }
    unordered_map<int,unordered_set<int>> graph;
    for (int i = 0; i < m; i++){
        graph[edges[i].second].insert(edges[i].first);
    }
    int dp[n+1];
    for (int i = 1; i <= n; i++){
        dp[i] = INT_MAX;
    }
    dp[1] = 1;
    stack<pair<int,int>> dfs;
    dfs.push({1,1});
    while (!dfs.empty()){
        auto temp = dfs.top();
        dfs.pop();
        for (int i : graph[temp.first]) {
            if (dp[i] > temp.second + 1) {
                dp[i] = temp.second + 1;
                dfs.push({i, dp[i]});
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++){
        ans += dp[i];
    }
    if (ans >= 2000000){
        cout << "INFINITE" << "\n";
        return;
    } else{
        cout << "FINITE" << "\n";
        cout << ans << "\n";
    }

    //not infinite, use a priority queue ordered by the number of elements left first, and then insertion order
    priority_queue<pair<pair<int,int>,int>> rahh;
    vector<int> answer;
    int currentprio = 0;
    for (int i = 1; i <= n; i++){
        rahh.push({{dp[i],0},i});
    }
    while (!rahh.empty()){
        auto grr = rahh.top();
        rahh.pop();
        answer.push_back(grr.second);
        currentprio -= 1;
        if (rahh.empty()){
            break;
        }
        if (grr.first.first > 1){
            rahh.push({{grr.first.first-1,currentprio},grr.second});
        }
    }
    for (int i = 0; i < (int) answer.size(); i++){
        cout << answer[i] << " ";
    }
    cout << "\n";


}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}