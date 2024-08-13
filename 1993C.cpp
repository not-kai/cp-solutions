#include <bits/stdc++.h>
using namespace std;
namespace LazySegmentTree{
    int segtree[400000 * 4][2];
    int n;
    void update(int left, int right, int value, int onleft=0, int onright=n-1, int treeindex=0){
        segtree[treeindex][0] += segtree[treeindex][1]*(onright-onleft+1);
        if (onleft != onright){
            segtree[treeindex*2+1][1] += segtree[treeindex][1];
            segtree[treeindex*2+2][1] += segtree[treeindex][1];
        }
        segtree[treeindex][1] = 0;
        if (onleft > right || onright < left){
            return;
        }
        if (onleft >= left && onright <= right){
            segtree[treeindex][0] += value*(onright-onleft+1);
            if (onleft != onright) {
                segtree[treeindex*2+1][1] += value;
                segtree[treeindex*2+2][1] += value;
            }
            return;
        }
        update(left, right, value, onleft, (onleft+onright)/2, treeindex*2+1);
        update(left, right, value, (onleft+onright+2)/2, onright, treeindex*2+2);
        segtree[treeindex][0] = segtree[treeindex*2+1][0] + segtree[treeindex*2+2][0];
    }
    int output(int left, int right, int onleft=0, int onright=n-1, int treeindex=0){
        if (onleft > right || onright < left){
            return 0;
        }
        if (onleft >= left && onright <= right){
            segtree[treeindex][0] += segtree[treeindex][1]*(onright-onleft+1);
            if (onleft != onright){
                segtree[treeindex*2+1][1] += segtree[treeindex][1];
                segtree[treeindex*2+2][1] += segtree[treeindex][1];
            }
            segtree[treeindex][1] = 0;
            return segtree[treeindex][0];
        }
        segtree[treeindex][0] += segtree[treeindex][1]*(onright-onleft+1);
        if (onleft != onright){
            segtree[treeindex*2+1][1] += segtree[treeindex][1];
            segtree[treeindex*2+2][1] += segtree[treeindex][1];
        }
        segtree[treeindex][1] = 0;
        return output(left, right, onleft, (onleft+onright)/2, treeindex*2+1) + output(left, right, (onleft+onright+2)/2, onright, treeindex*2+2);
    }
    void initialize(int maxn){
        n = maxn;
        for (int i = 0; i < 4*n; i++){
            segtree[i][0] = 0;
            segtree[i][1] = 0;
        }
    }
} //addition, 1 based indexing, range queries + range updates
void solve() {
    int n,k; cin >> n >> k;
    vector<int> times(n);
    for (int i = 0; i < n; i++){
        cin >> times[i];
    }
    sort(times.begin(), times.end());
    LazySegmentTree::initialize(2*k);
    for (int i = 0; i < n; i++){
        int start = times[i];
        start %= 2*k;
        int end = (times[i]+k-1)%(2*k);
        if (end >= start){
            LazySegmentTree::update(start, end,1);
        } else{
            LazySegmentTree::update(start,2*k - 1, 1);
            LazySegmentTree::update(0, end, 1);
        }
    }
    long long solution = LONG_LONG_MAX;
    for (int i = 0; i < 2*k; i++){
        if (LazySegmentTree::output(i,i) == n){
            if (times[n-1]%(2*k) == i){
                solution = min(solution, (long long) times[n-1]);
            }
            if (times[n-1]%(2*k) > i){
                solution = min(solution,(long long) (times[n-1]/(2*k))*2*k + i + 2*k);
            } else{
                solution = min(solution, (long long) (times[n-1]/(2*k))*2*k + i);
            }
        }
    }
    if (solution == LONG_LONG_MAX){
        cout << -1 << "\n";
    } else{
        cout << solution << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}
