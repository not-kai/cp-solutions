#include <bits/stdc++.h>
using namespace std;
#define MAXN 400000
namespace LazySegmentTree{
    int segtree[MAXN * 4][2];
    int n;
    void update(int left, int right, int value, int onleft=0, int onright=n-1, int treeindex=0){
        segtree[treeindex][0] = max(segtree[treeindex][0],segtree[treeindex][1]);
        if (onleft != onright){
            segtree[treeindex*2+1][1] = max(segtree[treeindex*2+1][1],segtree[treeindex][1]);
            segtree[treeindex*2+2][1] = max(segtree[treeindex*2+2][1], segtree[treeindex][1]);
        }
        segtree[treeindex][1] = -1;
        if (onleft > right || onright < left){
            return;
        }
        if (onleft >= left && onright <= right){
            segtree[treeindex][0] = max(segtree[treeindex][0], value);
            if (onleft != onright) {
                segtree[treeindex*2+1][1] = max(segtree[treeindex*2+1][1],value);
                segtree[treeindex*2+2][1] = max(segtree[treeindex*2+2][1],value);
            }
            return;
        }
        update(left, right, value, onleft, (onleft+onright)/2, treeindex*2+1);
        update(left, right, value, (onleft+onright+2)/2, onright, treeindex*2+2);
        segtree[treeindex][0] = max(segtree[treeindex*2+1][0], segtree[treeindex*2+2][0]);
    }
    int output(int left, int right, int onleft=0, int onright=n-1, int treeindex=0){
        if (left > right){
            return -1;
        }
        if (onleft > right || onright < left){
            return -1;
        }
        if (onleft >= left && onright <= right){
            segtree[treeindex][0] = max(segtree[treeindex][0],segtree[treeindex][1]);
            if (onleft != onright){
                segtree[treeindex*2+1][1] = max(segtree[treeindex*2+1][1],segtree[treeindex][1]);
                segtree[treeindex*2+2][1] = max(segtree[treeindex*2+2][1], segtree[treeindex][1]);
            }
            segtree[treeindex][1] = -1;
            return segtree[treeindex][0];
        }
        segtree[treeindex][0] = max(segtree[treeindex][0],segtree[treeindex][1]);
        if (onleft != onright){
            segtree[treeindex*2+1][1] = max(segtree[treeindex*2+1][1],segtree[treeindex][1]);
            segtree[treeindex*2+2][1] = max(segtree[treeindex*2+2][1], segtree[treeindex][1]);
        }
        segtree[treeindex][1] = -1;
        return max(output(left, right, onleft, (onleft+onright)/2, treeindex*2+1), output(left, right, (onleft+onright+2)/2, onright, treeindex*2+2));
    }
    void initialize(int maxn){
        n = maxn;
        for (int i = 0; i < 4*n; i++){
            segtree[i][0] = -1;
            segtree[i][1] = -1;
        }
    }
} //max lazy seg tree
bool comp(pair<int,int> a, pair<int,int> b){
    if (a.first == b.first){
        return a.second > b.second;
    } else{
        return a.first < b.first;
    }
}
void solve() {
    int n; cin >> n;
    vector<pair<int,int>> arr(n);
    map<pair<int,int>, vector<int>> pairtoanswer;
    for (int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
        pairtoanswer[arr[i]].push_back(i);
    }
    set<int> pq;
    for (int i = 0; i < n; i++){
        pq.insert(arr[i].first);
        pq.insert(arr[i].second);
    }
    unordered_map<int,int> truetocompress;
    unordered_map<int,int> compresstotrue;
    int tracker = 0;
    for (int i : pq){
        truetocompress[i] = tracker;
        compresstotrue[tracker] = i;
        tracker += 1;
    }
    vector<pair<int,int>> truearr(n);
    for (int i = 0; i < n; i++){
        truearr[i] = {truetocompress[arr[i].first], truetocompress[arr[i].second]};
    }
    sort(truearr.begin(), truearr.end(), comp);
    map<pair<int,int>,pair<int,int>> answers;
    multiset<int> rightvalues;
    LazySegmentTree::initialize(tracker);
    for (int i = 0; i < n; i++){
        auto it = rightvalues.lower_bound(truearr[i].second);
        int left,right;
        if (it == rightvalues.end()){
            right = truearr[i].second;
        } else{
            right = (*it);
        }
        left = LazySegmentTree::output(truearr[i].second,tracker-1);
        if (left == -1){
            left = truearr[i].first;
        }
        if (answers.find(truearr[i]) == answers.end()){
            answers[truearr[i]] = {left,right};
        }else {
            answers[truearr[i]] = {max(answers[truearr[i]].first, left), min(answers[truearr[i]].second, right)};
        }
        rightvalues.insert(truearr[i].second);
        LazySegmentTree::update(0,truearr[i].second,truearr[i].first);
    }
    vector<int> trueanswers(n);
    for (int i =0; i < n; i++){
        auto expand = answers[{truetocompress[arr[i].first], truetocompress[arr[i].second]}];
        trueanswers[i] = (arr[i].first - compresstotrue[expand.first]) + (compresstotrue[expand.second] - arr[i].second);
    }
    for (int i : trueanswers){
        cout << i << "\n";
    }



}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}