#include <bits/stdc++.h>
using namespace std;
#define MAXN 200000
namespace LazySegmentTree{
    int segtree[MAXN * 4][2];
    int n;
    void update(int left, int right, int value, int onleft=1, int onright=n, int treeindex=0){
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
    int output(int left, int right, int onleft=1, int onright=n, int treeindex=0){
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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q; cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    LazySegmentTree::initialize(n);
    vector<int> answers(n);
    for (int i = 0; i < n; i++){
        int left = 1; int right = n;
        int minworks = n+1;
        while (left <= right){
            int mid = (left+right)/2;
            if (1 + (LazySegmentTree::output(mid,mid)/mid) > arr[i]){ //run away
                left = mid+1;
            } else{
                minworks = min(minworks, mid);
                right = mid-1;
            }
        }
        answers[i] = minworks;
        LazySegmentTree::update(minworks,n,1);
    }
    for (int gg = 0; gg < q; gg++){
        int a,b; cin >> a >> b;
        if (answers[a-1] <= b){
            cout << "YES" << "\n";
        } else{
            cout << "NO" << "\n";
        }
    }


}
