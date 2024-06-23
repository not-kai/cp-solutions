#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
typedef long long i1;
namespace LazySegmentTree{
    i1 segtree[200001 * 4][2];
    i1 n;
    void update(i1 left, i1 right, i1 value, i1 onleft=1, i1 onright=n, i1 treeindex=0){
        if (onleft > right || onright < left){
            return;
        }
        if (onleft >= left && onright <= right){
            segtree[treeindex][0] += value*(onright-onleft+1);
            segtree[treeindex][0] %= MOD;
            if (onleft != onright) {
                segtree[treeindex*2+1][1] += value;
                segtree[treeindex*2+2][1] += value;
                segtree[treeindex*2+1][1] %= MOD;
                segtree[treeindex*2+2][1] %= MOD;
            }
            return;
        }
        update(left, right, value, onleft, (onleft+onright)/2, treeindex*2+1);
        update(left, right, value, (onleft+onright+2)/2, onright, treeindex*2+2);
        segtree[treeindex][0] = segtree[treeindex*2+1][0] + segtree[treeindex*2+2][0];
        segtree[treeindex][0] %= MOD;
    }
    i1 output(i1 left, i1 right, i1 onleft=1, i1 onright=n, i1 treeindex=0){
        if (onleft > right || onright < left){
            return 0;
        }
        if (onleft >= left && onright <= right){
            segtree[treeindex][0] += segtree[treeindex][1]*(onright-onleft+1);
            segtree[treeindex][0] %= MOD;
            if (onleft != onright){
                segtree[treeindex*2+1][1] += segtree[treeindex][1];
                segtree[treeindex*2+2][1] += segtree[treeindex][1];
                segtree[treeindex*2+1][1]  %=MOD;
                segtree[treeindex*2+2][1] %= MOD;
            }
            segtree[treeindex][1] = 0;
            return segtree[treeindex][0];
        }
        segtree[treeindex][0] += segtree[treeindex][1]*(onright-onleft+1);
        segtree[treeindex][0] %= MOD;
        if (onleft != onright){
            segtree[treeindex*2+1][1] += segtree[treeindex][1];
            segtree[treeindex*2+2][1] += segtree[treeindex][1];
            segtree[treeindex*2+1][1]  %=MOD;
            segtree[treeindex*2+2][1] %= MOD;
        }
        segtree[treeindex][1] = 0;
        return (output(left, right, onleft, (onleft+onright)/2, treeindex*2+1) + output(left, right, (onleft+onright+2)/2, onright, treeindex*2+2))%MOD;
    }
    void initialize(i1 maxn){
        n = maxn;
        for (i1 i = 0; i < 4*n; i++){
            segtree[i][0] = 0;
            segtree[i][1] = 0;
        }
    }
}
int main() {
    i1 n; cin >> n;
    vector<pair<i1,i1>> portals;
    vector<i1> portallocation;
    vector<i1> active;
    vector<i1> foreachportal;
    for (i1 i = 0; i < n; i++){
        i1 a,b; cin >> a >> b;
        portals.push_back({a,b});
        portallocation.push_back(a);
        i1 c; cin >> c; active.push_back(c);
        foreachportal.push_back(0);
    }

    /// FIX THIS SHIT SO THAT IT USES PORTAL INDEXES AS VALUES NOT THE COORDINATES
    LazySegmentTree::initialize(n);
    for (i1 i = n-1; i >= 0; i--){
        i1 highertolower = LazySegmentTree::output(i+1, i+1);
        i1 answer = 1;
        answer += highertolower;
        answer %= MOD;
        i1 numberoftimes;
        if (active[i]){
            numberoftimes = answer;
        } else{
            answer -= 1;
            numberoftimes = answer;
        }
        /*
         * answer += active[i];
        if (answer < 2){
            numberoftimes = 0;
        } else{
            answer -= 2;
            numberoftimes = 1;
            numberoftimes += answer;
        }
         */
        foreachportal[i] = numberoftimes;
        //cout << "updating " << (lower_bound(portallocation.begin(), portallocation.end(), portals[i].second)-portallocation.begin())+1 << " to " << i+1 << endl;
        LazySegmentTree::update((lower_bound(portallocation.begin(), portallocation.end(), portals[i].second)-portallocation.begin())+1, i+1, numberoftimes);
    }
    i1 distance = portals[portals.size()-1].first+1;
    for (i1 i = 0; i < n; i++){
        distance += foreachportal[i] * (portals[i].first - portals[i].second);
        distance %= MOD;
    }
    cout << distance << endl;

}
