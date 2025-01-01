    #include <bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp> // Common file
    #include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
    #include <ext/pb_ds/detail/standard_policies.hpp>
    using namespace __gnu_pbds;
    using namespace std;
    #define MAXN 100000
    namespace SegmentTree{
        int segtree[MAXN * 4];
        int n;
        void update(int index, int value, int onleft=0, int onright=n-1, int treeindex=0){
            if (onleft > index || onright < index){
                return;
            }
            if (onleft == onright){
                segtree[treeindex] = value;
                return;
            }
     
            update(index, value, onleft, (onleft+onright)/2, treeindex*2+1);
            update(index, value, (onleft+onright+2)/2, onright, treeindex*2+2);
            segtree[treeindex] = min(segtree[treeindex*2+1], segtree[treeindex*2+2]);
        }
        int output(int left, int right, int onleft=0, int onright=n-1, int treeindex=0){
            if (left > right){
                return INT_MAX-1;
            }
            if (onleft > right || onright < left){
                return INT_MAX-1;
            }
            if (onleft >= left && onright <= right){
                return segtree[treeindex];
            }
            return min(output(left, right, onleft, (onleft+onright)/2, treeindex*2+1),output(left, right, (onleft+onright+2)/2, onright, treeindex*2+2));
        }
        void initialize(int maxn){
            n = maxn;
            for (int i = 0; i < 4*n; i++){
                segtree[i] = INT_MAX-1;
            }
        }
    }
     
    void solve() {
        int n; cin >> n;
        vector<int> arr(n);
        SegmentTree::initialize(n);
        set<pair<int,int>> getmin;
        unordered_map<int,set<int>> positions;
        for (int i = 0 ; i < n; i++){
            cin >> arr[i];
            SegmentTree::update(i,arr[i]);
            getmin.insert({arr[i],i});
            positions[arr[i]].insert(i);
        }
        vector<int> answer(n);
        int bound = -1;
        int currletter = -1;
        int currmax = -1;
        for (int grr = 0; grr < n; grr++){
            pair<int,int> maybebounded = {SegmentTree::output(bound+1, n-1),*(positions[SegmentTree::output(bound+1, n-1)].lower_bound(bound))};
            pair<int,int> boundedmin;
            if (grr != 0 && maybebounded.first > currletter && maybebounded.second < currmax){
                boundedmin = {maybebounded.first + 1, maybebounded.second};
            } else{
                boundedmin = maybebounded;
            }
     
            pair<int,int> truemin = {(*getmin.begin()).first+1,(*getmin.begin()).second} ;
            if (boundedmin.first <= truemin.first){
                answer[grr] = boundedmin.first;
                bound = max(bound,boundedmin.second);
                positions[maybebounded.first].erase(boundedmin.second);
                SegmentTree::update(boundedmin.second, INT_MAX-1);
                getmin.erase({maybebounded.first, boundedmin.second});
                if (boundedmin.second > currmax){
                    currletter = max(answer[grr], currletter);
                    currmax = max(currmax, boundedmin.second);
                }
            } else{
                answer[grr] = truemin.first;
                bound = max(bound, truemin.second);
                positions[truemin.first-1].erase(truemin.second);
                SegmentTree::update(truemin.second, INT_MAX-1);
                getmin.erase({truemin.first-1, truemin.second});
                if (n > currmax) {
                    currletter = max(answer[grr], currletter);
                    currmax = max(currmax, n);
                }
            }
        }
        for (int i : answer){
            cout << i << " ";
        }
        cout << "\n";
     
     
     
    }
     
    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int t; cin >> t; for (int i = 0; i < t; i++){
            solve();
        }
    }
