#include <bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<
        pair<int,int>,
        null_type,
        less<>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
namespace SegmentTree{
    int segtree[300000 * 4];
    int n;
    void update(int index, int value, int onleft=0, int onright=n-1, int treeindex=0){
        if (onleft > index || onright < index){
            return;
        }
        if (onleft == onright){
            segtree[treeindex] += value;
            return;
        }

        update(index, value, onleft, (onleft+onright)/2, treeindex*2+1);
        update(index, value, (onleft+onright+2)/2, onright, treeindex*2+2);
        segtree[treeindex] = segtree[treeindex*2+1] + segtree[treeindex*2+2];
    }
    int output(int left, int right, int onleft=0, int onright=n-1, int treeindex=0){
        if (onleft > right || onright < left){
            return 0;
        }
        if (onleft >= left && onright <= right){
            return segtree[treeindex];
        }
        return output(left, right, onleft, (onleft+onright)/2, treeindex*2+1)+output(left, right, (onleft+onright+2)/2, onright, treeindex*2+2);
    }
    void initialize(int maxn){
        n = maxn;
        for (int i = 0; i < 4*n; i++){
            segtree[i] = 0;
        }
    }
} //addition, 1 based indexing, range queries + point updates
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q; cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<int> sansundertale(n);
    int valid = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] > (i+1)){
            sansundertale[i] = 1;
        } else{
            sansundertale[i] = (i+1) - arr[i] - valid;
            if (sansundertale[i] <= 0) {
                valid += 1;
            }
        }
    }
    vector<vector<int>> updates(n+1);
    ordered_set grr;
    for (int i = 0; i < n; i++){
        if (sansundertale[i] > 0){
            updates[0].push_back(i);
        }
        else{
            if (-sansundertale[i] >= grr.size()){
                grr.insert({i,i});
                updates[i+1].push_back(i);
            } else{
                auto value = (*grr.find_by_order(-sansundertale[i]));
                updates[value.first+1].push_back(i);
                grr.insert({value.first,i});
            }
        }
    }
    SegmentTree::initialize(n);
    vector<int> answertoqueries(q);
    vector<vector<pair<int,int>>> queries(n);
    for (int i = 0; i < q; i++){
        pair<int,int> query; cin >> query.first >> query.second;
        queries[query.first].push_back({query.second,i});
    }
    for (int i = 0; i < n; i++){
        for (int j : updates[i]){
            SegmentTree::update(j,1);
        }
        for (auto j : queries[i]){
            answertoqueries[j.second] = n - i - j.first - SegmentTree::output(i,n-j.first-1);
        }
    }
    for (int i = 0; i < q; i++){
        cout << answertoqueries[i] << "\n";
    }



}
