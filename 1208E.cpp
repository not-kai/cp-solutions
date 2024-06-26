#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000001
#define MAXLOG 22
typedef long long i1;
namespace LazySegmentTree{
    i1 segtree[MAXN * 4][2];
    i1 n;
    void update(i1 left, i1 right, i1 value, i1 onleft=0, i1 onright=n-1, i1 treeindex=0){
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
    i1 output(i1 left, i1 right, i1 onleft=0, i1 onright=n-1, i1 treeindex=0){
        if (left>right){
            return 0;
        }
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
    void initialize(i1 maxn){
        n = maxn;
        for (i1 i = 0; i < 4*n; i++){
            segtree[i][0] = 0;
            segtree[i][1] = 0;
        }
    }
} //addition, 1 based indexing, range queries + range updates
namespace SparseTable{
    i1 n, logn;
    int arr[MAXN], sparse[MAXN][MAXLOG][2];
    void calculateTable(){
        for (i1 i = 0; i < n; i++){
            sparse[i][0][0] = arr[i];
            sparse[i][0][1] = i;
        }
        for (i1 k = 1; k <= logn; k++){
            for (i1 i = 0; i+(1<<k)-1 < n; i++){
                sparse[i][k][0] = max(sparse[i][k-1][0], sparse[i+(1<<(k-1))][k-1][0]);
                if (sparse[i][k][0] == sparse[i][k-1][0]){
                    sparse[i][k][1] = sparse[i][k-1][1];
                } else{
                    sparse[i][k][1] = sparse[i+(1<<(k-1))][k-1][1];
                }
            }
        }
    }
    void initialize(i1 maxn){
        n = maxn;
        logn = __lg(maxn)+3;
    }
    pair<int,int> query(i1 left, i1 right){ //value, pos
        i1 differencelog = __lg(right-left+1);
        if (sparse[left][differencelog][0] > sparse[right-(1<<differencelog)+1][differencelog][0]){
            return {sparse[left][differencelog][0], sparse[left][differencelog][1]};
        } else{
            return {sparse[right-(1<<differencelog)+1][differencelog][0],sparse[right-(1<<differencelog)+1][differencelog][1]};
        }
    }
} //maximum range query, 0 based indexing, must read array directly, uses __lg so may not work for all compilers, O(nlog(n)) preprocessing with constant lookup times

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i1 n,w; cin >> n >> w;
    LazySegmentTree::initialize(w);
    for (i1 asdd = 0; asdd < n; asdd++){
        i1 l; cin >> l;
        SparseTable::initialize(l);
        vector<i1> arr(l);
        for (i1 i = 0 ; i < l; i++){
            cin >> arr[i];
            SparseTable::arr[i] = arr[i];
        }
        SparseTable::calculateTable();
        i1 diff = w - l;
        stack<pair<pair<i1,i1>,pair<i1,i1>>> idontwantrecursion; //left, right, right is inclusive, left is not
        idontwantrecursion.push({{0,l-1},{0,w}});
        while (!idontwantrecursion.empty()){
            auto grr = idontwantrecursion.top(); idontwantrecursion.pop();
            i1 left = grr.first.first; i1 right = grr.first.second;
            i1 effectiveright = grr.second.first;
            i1 effectiveleft = grr.second.second;
            auto pleasework = SparseTable::query(left,right);
            i1 maxthing = pleasework.first;
            i1 index = pleasework.second;
            i1 tempindex = max(effectiveright,index);
            if (maxthing < 0){
                LazySegmentTree::update(max(tempindex,diff), min(min(diff+index,effectiveleft-1),l-1), maxthing);
            } else {
                LazySegmentTree::update(tempindex, min(diff+index,effectiveleft-1), maxthing);
            }
            if (index > left){
                idontwantrecursion.push({{left,index-1},{effectiveright,min(index,effectiveleft)}});
            } if (index < right){
                idontwantrecursion.push({{index+1, right},{min(diff+index,effectiveleft-1)+1,effectiveleft}});
            }
        }
    }
    for (i1 i = 0; i < w; i++){
        cout << LazySegmentTree::output(i,i) << " ";
    }
}
