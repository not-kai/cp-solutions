#include <bits/stdc++.h>
using namespace std;
void solve() {

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; cin >> n >> m;
    int x,y,z; cin >> x >> y >> z;
    vector<vector<int>> graph(n+1);
    for (int i = 0; i < m; i++){
        int a,b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> colors(n+1);
    vector<pair<vector<int>, vector<int>>> nodes;
    for (int i = 1; i <= n; i++){
        if (colors[i] != 0){
            continue;
        } else{
            vector<int> one;
            vector<int> two;
            queue<int> dfs;
            dfs.push(i);
            colors[i] = 1;
            while (!dfs.empty()){
                int node = dfs.front(); dfs.pop();
                if (colors[node] == 1){
                    one.push_back(node);
                } else{
                    two.push_back(node);
                }
                for (int j : graph[node]){
                    if (colors[j] == colors[node]){
                        cout << "NO" << "\n";
                        return 0;
                    } else if (colors[j] == 0){
                        colors[j] = -1 * colors[node];
                        dfs.push(j);
                    }
                }
            }
            nodes.push_back({one,two});
        }
    }
    int dp[nodes.size()][y+1][2]; //picking on pair x, with y of y left to take, 2 marks true/false and coming from where
    memset(dp, 0, sizeof dp);
    dp[0][y - nodes[0].first.size()][0] = true;
    dp[0][y - nodes[0].first.size()][1] = y;
    dp[0][y - nodes[0].second.size()][0] = true;
    dp[0][y - nodes[0].second.size()][1] = y;
    for (int i = 1; i < nodes.size(); i++){
        for (int j = 0; j <= y; j++){
            if (j+nodes[i].first.size() <= y && dp[i-1][j+nodes[i].first.size()][0]){
                dp[i][j][0] = true;
                dp[i][j][1] = j+nodes[i].first.size();
            } else if (j+nodes[i].second.size() <= y && dp[i-1][j+nodes[i].second.size()][0]){
                dp[i][j][0] = true;
                dp[i][j][1] = j+nodes[i].second.size();
            } else{
                dp[i][j][0] = false;
                dp[i][j][1] = -1;
            }
        }
    }
    if (!dp[nodes.size()-1][0][0]){
        cout << "NO" << "\n"; return 0;
    } else{
        int curr = 0;
        for (int i = nodes.size()-1; i >= 0; i--){
            if (curr+nodes[i].second.size() == dp[i][curr][1]){
                swap(nodes[i].first, nodes[i].second);
            }
            curr += nodes[i].first.size();
        }
    }
    vector<int> finalans(n+1);
    for (auto i : nodes){
        for (int j : i.first){
            finalans[j] = 2;
        }
    }
    for (int i = 1; i <= n; i++){
        if (finalans[i] != 2) {
            if (x != 0) {
                finalans[i] = 1;
                x -= 1;
            } else {
                finalans[i] = 3;
            }
        }
    }
    cout << "YES" << "\n";
    for (int i = 1; i <= n; i++){
        cout << finalans[i];
    }
    cout << "\n";

}
