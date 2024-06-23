#include <bits/stdc++.h>
using namespace std;
namespace SegmentTree{
    int segtree[2000000 * 4];
    int n;
    void update(int index, int value, int onleft=1, int onright=n, int treeindex=0){
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
    int output(int left, int right, int onleft=1, int onright=n, int treeindex=0){
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
}
vector<int> a;
vector<int> b;
vector<int> pos;
void dc(int leftp, int rightp, int left, int right){
    if (left > right){
        return;
    }
    if (leftp > rightp){
        return;
    }
    int mid = (left+right)/2;
    int min = 0;
    int minindex = leftp;
    int temp = 0;
    for (int i = leftp; i < rightp; i++){
        if (a[i] > b[mid]){
            temp += 1;
        } else if (a[i] < b[mid]){
            temp -= 1;
            if (temp < min){
                min = temp;
                minindex = i+1;
            }
        }
    }
    pos[mid] = minindex;
    dc(leftp, minindex, left, mid-1);
    dc(minindex, rightp, mid+1, right);
}
void solve() {
    int n,m; cin >> n >> m;
    a.clear();
    a.resize(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    b.clear();
    b.resize(m);
    for (int i = 0; i < m; i++){
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    pos.clear();
    pos.resize(m);
    dc(0,n,0,m-1);
    vector<pair<int,int>> final;
    int pointer = 0;
    for (int i = 0; i < n; i++){
        while (pos[pointer] <= i && pointer < m){
            final.push_back({b[pointer],final.size()});
            pointer += 1;
        }
        final.push_back({a[i],final.size()});
    }
    while (pointer < m){
        final.push_back({b[pointer],final.size()});
        pointer += 1;
    }
    SegmentTree::initialize(n+m);
    sort(final.begin(), final.end());
    reverse(final.begin(), final.end());
    long long answer = 0;
    for (int i = 0; i < n+m; i++){
        answer += SegmentTree::output(1, final[i].second+1);
        SegmentTree::update(final[i].second+1, 1);
    }
    cout << answer << "\n";

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;for (int i = 0; i < t; i++){
        solve();
    }
}