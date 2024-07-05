#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000
#define MAXLOG 20
typedef long long i1;
namespace MaxSparseTable{
    i1 n, logn;
    i1 arr[MAXN], sparse[MAXN][MAXLOG];
    void calculateTable(){
        for (i1 i = 0; i < n; i++){
            sparse[i][0] = arr[i];
        }
        for (i1 k = 1; k <= logn; k++){
            for (i1 i = 0; i+(1<<k)-1 < n; i++){
                sparse[i][k] = max(sparse[i][k-1], sparse[i+(1<<(k-1))][k-1]);
            }
        }
    }
    void initialize(i1 maxn){
        n = maxn;
        logn = __lg(maxn)+3;
    }
    i1 query(i1 left, i1 right){
        i1 differencelog = __lg(right-left+1);
        return max(sparse[left][differencelog], sparse[right-(1<<differencelog)+1][differencelog]);
    }
} //minimum range query, 0 based indexing, must read array directly, uses __lg so may not work for all compilers, O(nlog(n)) preprocessing with constant lookup times
namespace MinSparseTable{
    i1 n, logn;
    i1 arr[MAXN], sparse[MAXN][MAXLOG];
    void calculateTable(){
        for (i1 i = 0; i < n; i++){
            sparse[i][0] = arr[i];
        }
        for (i1 k = 1; k <= logn; k++){
            for (i1 i = 0; i+(1<<k)-1 < n; i++){
                sparse[i][k] = min(sparse[i][k-1], sparse[i+(1<<(k-1))][k-1]);
            }
        }
    }
    void initialize(i1 maxn){
        n = maxn;
        logn = __lg(maxn)+3;
    }
    i1 query(i1 left, i1 right){
        i1 differencelog = __lg(right-left+1);
        return min(sparse[left][differencelog], sparse[right-(1<<differencelog)+1][differencelog]);
    }
} //minimum range query, 0 based indexing, must read array directly, uses __lg so may not work for all compilers, O(nlog(n)) preprocessing with constant lookup times
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i1 n,q; cin >> n >> q;
    vector<i1> a(n);
    vector<i1> b(n);
    vector<i1> diff(n);
    for (i1 i = 0; i < n; i++){
        cin >> a[i];
    } for (i1 i = 0; i < n; i++){
        cin >> b[i];
        diff[i] = a[i] - b[i];
    }
    vector<i1> prefixsums(n);
    prefixsums[0] = diff[0];
    for (i1 i = 1; i < n; i++){
        prefixsums[i] = prefixsums[i-1] + diff[i];
    }
    MaxSparseTable::initialize(n);
    MinSparseTable::initialize(n);
    for (i1 i = 0; i < n; i++){
        MinSparseTable::arr[i] = prefixsums[i];
        MaxSparseTable::arr[i] = prefixsums[i];
    }
    MaxSparseTable::calculateTable();
    MinSparseTable::calculateTable();
    for (i1 jojo = 0; jojo < q; jojo++){
        i1 l,r; cin >> l >> r; l -= 1; r -= 1;
        if (l == 0 && prefixsums[r] != 0){
            cout << -1 << "\n";
            continue;
        } else if (prefixsums[r] - prefixsums[l-1] != 0 && l != 0){
            cout << -1 << "\n";
            continue;
        }
        i1 max1 = MaxSparseTable::query(l,r);
        if (l != 0){
            max1 -= prefixsums[l-1];
        }
        if (max1 > 0){
            cout << -1 << "\n";
            continue;
        }
        i1 min1 = MinSparseTable::query(l,r);
        if (l != 0){
            min1 -= prefixsums[l-1];
        }
        cout << max(abs(max1), abs(min1)) << "\n";
    }

}
