#include <bits/stdc++.h>
using namespace std;
int n;
unordered_map<int, unordered_set<int>> tree;
int parents[200001];
int treedp[200001];
void dfsforparents(int node){
    for (int i : tree[node]){
        if (i == parents[node]){
            continue;
        }
        parents[i] = node;
        dfsforparents(i);
    }
}
int dp(int node){
    int answer = 0;
    for (int i : tree[node]){
        if (i == parents[node]){
            continue;
        }
        answer += dp(i);
    }
    if (answer == 0 && treedp[node] == 1){
        return 1;
    } else if (answer == 0 && treedp[node] == 0){
        return 0;
    } else if (treedp[parents[node]] == 1 && answer == 2){
        return 3;
    } else{
        return answer;
    }
}
void solve(){
    int q; cin >> q;
    unordered_set<int> special;
    for (int i = 0; i < q; i++){
        int temp; cin >> temp; special.insert(temp);
    }
    memset(treedp, 0, sizeof treedp);
    for (int i : special){
        treedp[i] = 1;
    }
    if (dp(1) >= 3){
        cout << "NO" << "\n";
    } else{
        cout << "YES" << "\n";
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < n-1; i++){
        int a,b;
        cin >> a >> b;
        tree[a].insert(b);
        tree[b].insert(a);
    }
    dfsforparents(1);
    int t; cin >> t;
    for (int i = 0; i < t; i++){
        solve();
    }
}
