#include <bits/stdc++.h>

typedef long long i1;
using namespace std;
i1 n;
i1 arr[200000];
i1 segtree[800000][4]; //0 means front/back are off, 1 means front is on, 2 means back is on, 3 means both
void changeEdge(i1 left, i1 right, i1 treeindex, i1 index, i1 value){
    if (index < left || index > right){
        return;
    } else if (left == right){
        segtree[treeindex][0] = 0;
        segtree[treeindex][1] = value;
        segtree[treeindex][2] = value;
        segtree[treeindex][3] = value;
        return;
    }
    changeEdge(left, (left+right)/2, treeindex*2+1, index, value);
    changeEdge((left+right+2)/2, right, treeindex*2+2, index, value);
    if (right-left >1) {
        segtree[treeindex][0] = segtree[treeindex * 2 + 1][2] + segtree[treeindex * 2 + 2][1]; //both are on
        segtree[treeindex][0] = min(segtree[treeindex][0], segtree[treeindex * 2 + 1][2] +
                                                           segtree[treeindex * 2 + 2][0]); //back of first is on
        segtree[treeindex][0] = min(segtree[treeindex][0], segtree[treeindex * 2 + 1][0] +
                                                           segtree[treeindex * 2 + 2][1]); //front of second is on
        segtree[treeindex][1] = segtree[treeindex * 2 + 1][3] + segtree[treeindex * 2 + 2][1];
        segtree[treeindex][1] = min(segtree[treeindex][1],
                                    segtree[treeindex * 2 + 1][3] + segtree[treeindex * 2 + 2][0]);
        segtree[treeindex][1] = min(segtree[treeindex][1],
                                    segtree[treeindex * 2 + 1][1] + segtree[treeindex * 2 + 2][1]);

        segtree[treeindex][2] = segtree[treeindex * 2 + 1][2] + segtree[treeindex * 2 + 2][3];
        segtree[treeindex][2] = min(segtree[treeindex][2],
                                    segtree[treeindex * 2 + 1][0] + segtree[treeindex * 2 + 2][3]);
        segtree[treeindex][2] = min(segtree[treeindex][2],
                                    segtree[treeindex * 2 + 1][2] + segtree[treeindex * 2 + 2][2]);

        segtree[treeindex][3] = segtree[treeindex * 2 + 1][3] + segtree[treeindex * 2 + 2][3];
        segtree[treeindex][3] = min(segtree[treeindex][3],
                                    segtree[treeindex * 2 + 1][1] + segtree[treeindex * 2 + 2][3]);
        segtree[treeindex][3] = min(segtree[treeindex][3],
                                    segtree[treeindex * 2 + 1][3] + segtree[treeindex * 2 + 2][2]);
    } else if (right-left <= 1){
        segtree[treeindex][0] = LONG_MAX;
        if (right < n-2) {
            segtree[treeindex][1] = segtree[treeindex * 2 + 1][1];
        } else{
            segtree[treeindex][1] = LONG_MAX;
        }
        if (left > 0) {
            segtree[treeindex][2] = segtree[treeindex * 2 + 2][1];
        } else{
            segtree[treeindex][2] = LONG_MAX;
        }
        segtree[treeindex][3] = segtree[treeindex*2+1][1] + segtree[treeindex*2+2][1];
        return;
    }
    if (left == 0){
        segtree[treeindex][0] = LONG_MAX;
        segtree[treeindex][2] = LONG_MAX;
    }
    if (right == n-2){
        segtree[treeindex][0] = LONG_MAX;
        segtree[treeindex][1] = LONG_MAX;
    }
}
void changeEdge(i1 index, i1 value){
    changeEdge(0, n-2, 0, index, value);
}
int main() {
    cin >> n;
    for (i1 i = 0; i < n-1; i++){
        cin >> arr[i];
        changeEdge(i, arr[i]);
    }
    i1 q; cin >> q;
    for (i1 i = 0; i < q; i++){
        i1 k, temp; cin >> k >> temp;
        k -= 1;
        changeEdge(k, temp);
        cout << segtree[0][3]*2 << "\n";
    }
}
