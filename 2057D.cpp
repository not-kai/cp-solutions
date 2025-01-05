#include <bits/stdc++.h>

using namespace std;
#define MAXN 200000
namespace SegmentTree{
    int segtree[MAXN * 4][3];
    int n;
    void update(int index, int value, int onleft=0, int onright=n-1, int treeindex=0){
        if (onleft > index || onright < index){
            return;
        }
        if (onleft == onright){
            segtree[treeindex][0] = value-index;
            segtree[treeindex][1] = index-value;
            segtree[treeindex][2] = 0;
            return;
        }

        update(index, value, onleft, (onleft+onright)/2, treeindex*2+1);
        update(index, value, (onleft+onright+2)/2, onright, treeindex*2+2);
        segtree[treeindex][0] = max(segtree[treeindex*2+1][0], segtree[treeindex*2+2][0]);
        segtree[treeindex][1] = max(segtree[treeindex*2+1][1], segtree[treeindex*2+2][1]);
        segtree[treeindex][2] = max(segtree[treeindex*2+1][2],segtree[treeindex*2+2][2]);
        segtree[treeindex][2] = max(segtree[treeindex][2], segtree[treeindex*2+2][0] + segtree[treeindex*2+1][1]);
    }
    void initialize(int maxn){
        n = maxn;
        for (int i = 0; i < 4*n; i++){
            segtree[i][0] = INT_MIN;
            segtree[i][1] = INT_MIN;
            segtree[i][2] = 0;
        }
    }
}

void solve() {
    int n,q; cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    SegmentTree::initialize(n);
    for (int i = 0; i < n; i++){
        SegmentTree::update(i,arr[i]);
    }
    vector<int> answers(q+1,INT_MIN);
    vector<pair<int,int>> queries(q);
    for (int i = 0; i < q; i++){
        cin >> queries[i].first >> queries[i].second;
    }
    answers[0] = SegmentTree::segtree[0][2];
    for (int i = 0; i < q; i++){
        SegmentTree::update(queries[i].first-1, queries[i].second);
        answers[i+1] = SegmentTree::segtree[0][2];
    }
    SegmentTree::initialize(n);
    reverse(arr.begin(), arr.end());
    for (int i = 0; i < n; i++){
        SegmentTree::update(i,arr[i]);
    }
    answers[0] = max(answers[0], SegmentTree::segtree[0][2]);
    for (int i = 0; i < q; i++){
        SegmentTree::update(n-1-(queries[i].first-1), queries[i].second);
        answers[i+1] = max(answers[i+1],SegmentTree::segtree[0][2]);
    }

    for (int i = 0; i < q+1; i++){
        cout << answers[i] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}