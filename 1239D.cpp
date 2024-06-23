#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
namespace SCC{
    int counter = 1;
    int num[1000000+1], low[1000000+1];
    int visited[1000000+1];
    stack<int> rah;
    vector<vector<int>> SCCs;
    void dfs(int node){
        num[node] = low[node] = counter;
        counter++;
        rah.push(node);
        visited[node] = 1; //0 means not visited, 1 means in stack, 2 means already processed
        for (int i : graph[node]){
            if (visited[i] == 0){
                dfs(i);
                low[node] = min(low[node], low[i]);
            } else if (visited[i] == 1){
                low[node] = min(low[node], num[i]);
            }
        }
        if (num[node] == low[node]){
            vector<int> scc;
            while (rah.top() != node){
                scc.push_back(rah.top()); visited[rah.top()] = 2; rah.pop();
            }
            scc.push_back(rah.top()); visited[rah.top()] = 2; rah.pop();
            SCCs.push_back(scc);
        }
    }
    void SCC(int nodes){
        while (!rah.empty()){
            rah.pop();
        }
        SCCs.clear();
        for (int i = 1; i <= nodes; i++){
            num[i] = 0;
            low[i] = 0;
            visited[i] = 0;
        }
        counter = 1;
        for (int i = 1; i <= nodes; i++){
            if (visited[i] == 0){
                dfs(i);
            }
        }
    }
} //O(n+m)? strongly connected components
void solve() {
    int n,m; cin >> n >> m;
    graph.clear();
    graph.resize(n+1);
    for (int i = 0; i < m; i++){
        int a,b; cin >> a >> b;
        if (a != b) {
            graph[a].push_back(b);
        }
    }
    SCC::SCC(n);
    if (SCC::SCCs.size() == 1){
        cout << "NO" << "\n";
        return;
    } else{
        cout << "YES" << "\n";
        cout << SCC::SCCs[0].size() << " " << n-SCC::SCCs[0].size() << "\n";
        for (int i : SCC::SCCs[0]){
            cout << i << " ";
        }
        cout << "\n";
        for (int i = 1; i < SCC::SCCs.size(); i++){
            for (int j : SCC::SCCs[i]){
                cout << j << " ";
            }
        }
        cout << "\n";
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}