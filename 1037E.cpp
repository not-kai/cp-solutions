#include <bits/stdc++.h>

using namespace std;

void solve() {

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,k; cin >> n >> m >> k;
    vector<unordered_set<int>> graph(n);
    vector<pair<int,int>> edges;
    for (int i = 0; i < m; i++){
        int a,b; cin >> a >> b;
        a-= 1; b -= 1;
        edges.push_back({a,b});
        graph[a].insert(b);
        graph[b].insert(a);
    }
    vector<int> answers(m);
    vector<bool> ingroup(n,true);
    queue<int> q;
    for (int i = 0; i < n; i++){
        if (graph[i].size() < k){
            ingroup[i] = false;
            q.push(i);
        }
    }
    while (!q.empty()){
        int node = q.front(); q.pop();
        for (int i : graph[node]){
            graph[i].erase(node);
            if (graph[i].size() < k && ingroup[i]){
                ingroup[i] = false;
                q.push(i);
            }
        }
        graph[node].clear();
    }
    int curr = 0;
    for (int i = 0; i < n; i++){
        if (ingroup[i]){
            curr += 1;
        }
    }
    answers[m-1] = curr;
    for (int edge = m-1; edge >= 1; edge--){
        int a = edges[edge].first; int b = edges[edge].second;
        answers[edge-1] = answers[edge];
        if (ingroup[a] && ingroup[b]){
            graph[a].erase(b);
            graph[b].erase(a);
            queue<int> q2;
            if (graph[a].size() < k){
                ingroup[a] = false;
                q2.push(a);
            }
            if (graph[b].size() < k){
                ingroup[b] = false;
                q2.push(b);
            }
            while (!q2.empty()){
                answers[edge-1] -= 1;
                int node = q2.front(); q2.pop();
                for (int i : graph[node]){
                    graph[i].erase(node);
                    if (graph[i].size() < k && ingroup[i]){
                        ingroup[i] = false;
                        q2.push(i);
                    }
                }
                graph[node].clear();
            }
        }
    }
    for (int i : answers){
        cout << i << "\n";
    }
}
