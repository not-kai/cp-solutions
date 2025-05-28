    #include <bits/stdc++.h>
    using namespace std;
    #define MAXN 1200002
    namespace SegmentTree{
        int segtree[MAXN * 4];
        int n;
        void update(int index, int value, int onleft=0, int onright=1200001, int treeindex=0){
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
        int output(int left, int right, int onleft=0, int onright=1200001, int treeindex=0){
            if (onleft > right || onright < left){
                return 0;
            }
            if (onleft >= left && onright <= right){
                return segtree[treeindex];
            }
            return output(left, right, onleft, (onleft+onright)/2, treeindex*2+1)+output(left, right, (onleft+onright+2)/2, onright, treeindex*2+2);
        }
        void initialize(){
            n = 1200002;
            for (int i = 0; i < 4*n; i++){
                segtree[i] = 0;
            }
        }
    } //addition, 1 based indexing, range queries + point updates
     
    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n; cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++){
            char temp; cin >> temp;
            if (temp == '0'){
                arr[i] = 1;
            } else{
                arr[i] = -3;
            }
        }
        SegmentTree::initialize();
        SegmentTree::update(900000,1);
        int prefixsum = 0;
        long long ans = 0;
        for (int i =0; i < n; i++){
            prefixsum += arr[i];
            ans += SegmentTree::output(prefixsum+1+900000,prefixsum+1+900000);
            ans += SegmentTree::output(0,prefixsum-2+900000);
            SegmentTree::update(prefixsum+900000,1);
     
        }
        cout << ans << "\n";
     
     
    }
