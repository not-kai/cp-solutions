#include <bits/stdc++.h>
using namespace std;
unordered_map<int, vector<int>> tree;
int sizes[100001];
int parents[100001];
void getparents(int node){
    for (int i : tree[node]){
        if (i == parents[node]){
            continue;
        }
        parents[i] = node;
        getparents(i);
    }
}
int getsizes(int node){
    if (sizes[node] != 0){
        return sizes[node];
    }
    int currsize = 1;
    for (int i : tree[node]){
        if (i == parents[node]){
            continue;
        }
        currsize += getsizes(i);
    }
    sizes[node] = currsize;
    return currsize;
}
pair<int,pair<int,bool>> grr(int node, int maxsize){ //size, number of k, did/not use last edge
    int currsize = 1;
    int currk = 0;
    for (int i : tree[node]){
        if (i == parents[node]){
            continue;
        }
        auto outcome = grr(i, maxsize);
        if (!outcome.second.second){
            currsize += outcome.first;
        }
        currk += outcome.second.first;
    }
    if (currsize >= maxsize){
        return {0,{currk+1, true}};
    } else{
        return {currsize, {currk, false}};
    }
}
void solve() {
    int n; cin >> n;
    int k; cin >> k;
    tree.clear();
    for (int i = 0; i < n-1; i++){
        sizes[i+1] = 0;
        parents[i+1] = 0;
        int a,b; cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    sizes[n] = 0;
    parents[n] = 0;
    getparents(1);
    getsizes(1);
    int left = 1;
    int right = n/(k);
    int maxworks = 1;
    while (left <= right){
        int mid = (left+right)/2;
        auto outcome = grr(1, mid);
        if (outcome.second.first > k){
            left = mid+1;
            maxworks = max(maxworks, mid);
        } else{
            right = mid-1;
        }
    }
    cout << maxworks << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0; i < t; i++){solve();}
}