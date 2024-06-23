#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001
typedef long long i1;
namespace LazySegmentTree{
    i1 segtree[MAXN * 4][3]; //0 means no update, 1 means update
    i1 n;
    void update(i1 left, i1 right, i1 value, i1 onleft=0, i1 onright=n-1, i1 treeindex=0){
        if (segtree[treeindex][2]) {
            segtree[treeindex][0] = segtree[treeindex][1] * (onright - onleft + 1);
            if (onleft != onright) {
                segtree[treeindex * 2 + 1][1] = segtree[treeindex][1];
                segtree[treeindex * 2 + 2][1] = segtree[treeindex][1];
                segtree[treeindex*2+1][2] = 1;
                segtree[treeindex*2+2][2] = 1;
            }
            segtree[treeindex][2] = 0;
        }
        if (onleft > right || onright < left){
            return;
        }
        if (onleft >= left && onright <= right){
            segtree[treeindex][0] = value*(onright-onleft+1);
            if (onleft != onright) {
                segtree[treeindex*2+1][1] = value;
                segtree[treeindex*2+2][1] = value;
                segtree[treeindex*2+1][2] = 1;
                segtree[treeindex*2+2][2] = 1;
            }
            return;
        }
        update(left, right, value, onleft, (onleft+onright)/2, treeindex*2+1);
        update(left, right, value, (onleft+onright+2)/2, onright, treeindex*2+2);
        segtree[treeindex][0] = segtree[treeindex*2+1][0] + segtree[treeindex*2+2][0];
    }
    i1 output(i1 left, i1 right, i1 onleft=0, i1 onright=n-1, i1 treeindex=0){
        if (onleft > right || onright < left){
            return 0;
        }
        if (onleft >= left && onright <= right){
            if (segtree[treeindex][2]) {
                segtree[treeindex][0] = segtree[treeindex][1] * (onright - onleft + 1);
                if (onleft != onright) {
                    segtree[treeindex * 2 + 1][1] = segtree[treeindex][1];
                    segtree[treeindex * 2 + 2][1] = segtree[treeindex][1];
                    segtree[treeindex*2+1][2] = 1;
                    segtree[treeindex*2+2][2] = 1;
                }
                segtree[treeindex][2] = 0;
            }
            return segtree[treeindex][0];
        }
        if (segtree[treeindex][2]) {
            segtree[treeindex][0] = segtree[treeindex][1] * (onright - onleft + 1);
            if (onleft != onright) {
                segtree[treeindex * 2 + 1][1] = segtree[treeindex][1];
                segtree[treeindex * 2 + 2][1] = segtree[treeindex][1];
                segtree[treeindex*2+1][2] = 1;
                segtree[treeindex*2+2][2] = 1;
            }
            segtree[treeindex][2] = 0;
        }
        return output(left, right, onleft, (onleft+onright)/2, treeindex*2+1) + output(left, right, (onleft+onright+2)/2, onright, treeindex*2+2);
    }
    void initialize(i1 maxn){
        n = maxn;
        for (i1 i = 0; i < 4*n; i++){
            segtree[i][0] = 0;
            segtree[i][2] = 0;
        }
    }
} //addition, 1 based indexing, range queries + range updates
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i1 n; cin >> n;
    vector<i1> arr(n);
    for (i1 i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<i1> k(n-1);
    for (i1 i = 0; i < n-1; i++){
        cin >> k[i];
    }
    vector<i1> prefixgrrs(n);
    for (i1 i = 1; i < n; i++){
        prefixgrrs[i] = prefixgrrs[i-1] + k[i-1];
    }
    vector<i1> truearr(n);
    for (i1 i = 0; i < n; i++){
        truearr[i] = arr[i] - prefixgrrs[i];
    }
    LazySegmentTree::initialize(n);
    for (i1 i = 0; i < n; i++){
        LazySegmentTree::update(i,i,truearr[i]);
    }
    vector<i1> prefixofprefix(n);
    prefixofprefix[0] = prefixgrrs[0];
    for (i1 i = 1; i < n; i++){
        prefixofprefix[i] = prefixofprefix[i-1] + prefixgrrs[i];
    }
    i1 q; cin >> q;
    for (i1 jojo = 0; jojo < q; jojo++){
        char type; cin >> type;
        if (type == 's'){
            i1 a,b; cin >> a >> b;
            a -= 1;
            b -= 1;
            i1 answer = LazySegmentTree::output(a,b);
            answer += prefixofprefix[b];
            if (a > 0){
                answer -= prefixofprefix[a-1];
            }
            cout << answer << "\n";
        } else{
            i1 index; cin >> index; index -= 1;
            i1 originalvalue = LazySegmentTree::output(index,index);
            i1 change; cin >> change;
            i1 newvalue = originalvalue + change;
            i1 left = index; i1 right = n-1;
            i1 works = index;
            while (left <= right){
                i1 mid = (left+right)/2;
                if (LazySegmentTree::output(mid,mid) > newvalue){
                    right = mid-1;
                } else{
                    works = max(works, mid);
                    left = mid+1;
                }
            }
            LazySegmentTree::update(index, works, newvalue);
        }
    }





}