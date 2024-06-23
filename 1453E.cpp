#include <bits/stdc++.h>
using namespace std;
int parents[200001];
int minchain[200001];
int maxbetweensubtree[200001];
void rah(int node, unordered_map<int,unordered_set<int>> &tree){
    for (int i : tree[node]){
        if (i == parents[node]){
            continue;
        } else{
            parents[i] =  node;
            rah(i, tree);
        }
    }
}
int getminchains(int node, unordered_map<int,unordered_set<int>> &tree){
    if (minchain[node] != 0){
        return minchain[node];
    }
    int answer = INT_MAX;
    for (int i : tree[node]){
        answer = min(answer,getminchains(i, tree));
    }
    if (answer == INT_MAX){
        minchain[node]=0;
        return 0;
    } else{
        minchain[node] = 1+answer;
        return 1+answer;
    }

}
void solve(){
    unordered_map<int, unordered_set<int>> tree;
    int n; cin >> n;
    for (int i = 0; i < n-1; i++){
        int a,b;
        cin >> a >>  b;
        tree[a].insert(b);
        tree[b].insert(a);
    }
    for (int i = 1; i <= n; i++){
        parents[i] = 0;
        minchain[i] = 0;
        maxbetweensubtree[i] = 0;
    }
    rah(1, tree);
    for (int i = 2; i <= n; i++){
        tree[i].erase(parents[i]);
    }
    getminchains(1, tree);
    /*
    for (int i = 1; i <= n; i++){
        cout << minchain[i] << " ";
    }
     cout << "\n";
     */
    int answer = 0;
    for (int i = 1; i <= n; i++){
        int maxchain = -1;
        int secondmaxchain = -1;
        for (int k : tree[i]){
            secondmaxchain = max(secondmaxchain, minchain[k]);
            if (maxchain < secondmaxchain){
                swap(maxchain, secondmaxchain);
            }
        }
        if (i == 1){
            answer = max(answer, maxchain+1);
            answer = max(answer, secondmaxchain+2);
        } else{
            answer = max(answer, maxchain+2);
        }
    }
    cout << answer << "\n";
}
int main() {
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}
