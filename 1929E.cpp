#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n; cin >> n;
    vector<vector<int>> tree(n);
    for (int i = 0; i < n-1; i++){
        int a,b; cin >> a >> b;
        a -= 1; b -= 1;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    vector<vector<int>> parents(20,vector<int>(n));
    vector<int> depth(n);
    parents[0][0] = 0;
    depth[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()){
        int node = q.front(); q.pop();
        for (int i : tree[node]){
            if (i != parents[0][node]){
                parents[0][i] = node;
                depth[i] = depth[node]+1;
                q.push(i);
            }
        }
    }
    for (int i = 1; i < 20; i++){
        for (int j = 0; j < n; j++){
            parents[i][j] = parents[i-1][parents[i-1][j]];
        }
    }
    map<pair<int,int>, vector<int>> edgestorange;
    int k; cin >> k;
    for (int i = 0; i < k; i++){
        int l,r; cin >> l >> r;
        l -= 1; r -= 1;
        int a = l;
        int b = r;
        int lca;
        if (depth[a] > depth[b]){
            int diff = depth[a] - depth[b];
            for (int j = 19; j >= 0; j--){
                if ((1<<j)&diff){
                    a = parents[j][a];
                }
            }
        } else if (depth[a] < depth[b]){
            int diff = depth[b] - depth[a];
            for (int j = 19; j >= 0; j--){
                if ((1<<j)&diff){
                    b = parents[j][b];
                }
            }
        }
        if ( a== b){
            lca= a;
        }
        else {
            for (int j = 19; j >= 0; j--) {
                if (parents[j][a] != parents[j][b]) {
                    a = parents[j][a];
                    b = parents[j][b];
                }
            }
            lca = parents[0][a];
        }

        while (l != lca){
            edgestorange[{min(l, parents[0][l]), max(l, parents[0][l])}].push_back(i);
            l = parents[0][l];
        }
        while (r != lca){
            edgestorange[{min(r, parents[0][r]), max(r, parents[0][r])}].push_back(i);
            r = parents[0][r];
        }
    }
    vector<int> transitions;
    vector<int> truetransitions;
    for (auto i : edgestorange){
        int start = 0;
        for (int j : i.second){
            start += (1 << j);

        }
        transitions.push_back(start);
    }
    sort(transitions.begin(), transitions.end(), greater<>());
    for (int i = 0; i < transitions.size(); i++){
        bool covered = false;
        for (int j : truetransitions){
            if ((j&transitions[i]) == transitions[i]){
                covered = true;
                break;
            }
        }
        if (!covered){
            truetransitions.push_back(transitions[i]);
        }
    }
    vector<vector<int>> bitmask((1<<k),vector<int>(truetransitions.size(),9999999));
    bitmask[0][0] = 0;
    bitmask[truetransitions[0]][0] = 1;
    for (int i = 0; i < truetransitions.size()-1; i++){
        for (int j = 0; j < (1 << k); j++){
            bitmask[j][i+1] = min(bitmask[j][i+1], bitmask[j][i]);
            bitmask[j|(truetransitions[i+1])][i+1] = min( bitmask[j|(truetransitions[i+1])][i+1], bitmask[j][i] + 1);
        }
    }
    cout << bitmask[(1<<k)-1][truetransitions.size()-1] << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}
