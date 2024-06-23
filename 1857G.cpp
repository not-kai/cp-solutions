#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
typedef long long i1;

long long exp(long long x, long long n, long long m) {
    x %= m;  // note: m * m must be less than 2^63 to avoid ll overflow
    long long res = 1;
    while (n > 0) {
        if (n % 2 == 1) { res = res * x % m; }
        x = x * x % m;
        n /= 2;
    }
    return res;
}
namespace DisjointSetUnion{
    i1 dsu[200000+1], rank[200000+1], size[200001];
    i1 n;
    i1 connectedcomponents;
    i1 getParent(i1 x){
        if (dsu[x]==x){
            return x;
        }
        dsu[x] = getParent(dsu[x]);
        return dsu[x];
    }
    i1 getSize(i1 x){
        if (dsu[x]==x){
            return size[x];
        }
        dsu[x] = getParent(dsu[x]);
        return size[dsu[x]];
    }
    void uniteSets(i1 x, i1 y){
        i1 parent1(getParent(x)), parent2(getParent(y));
        if (parent1 == parent2){
            return;
        }
        if (rank[parent1] < rank[parent2]){
            swap(parent1, parent2);
        }
        dsu[parent2] = parent1;
        rank[parent1] = max(rank[parent1], rank[parent2]+1);
        size[parent1] += size[parent2];
        connectedcomponents -= 1;
    }
    bool sameSet(i1 x, i1 y){
        return (getParent(x) == getParent(y));
    }
    void initialize(i1 maxn){
        n = maxn;
        connectedcomponents = n;
        for (i1 i = 1; i <= n; i++){
            dsu[i] = i;
            rank[i] = 1;
            size[i] = 1;
        }
    }
} //can use 1 or 0 based indexing
void solve(){
    i1 n; cin >> n;
    i1 maxedge; cin >> maxedge;
    unordered_map<i1, unordered_set<i1>> tree;
    set<pair<i1,pair<i1,i1>>> alledges;
    for (i1 i = 0; i < n-1; i++){
        i1 a, b, weight;
        cin >> a >>  b >> weight;
        tree[a].insert(b);
        tree[b].insert(a);
        alledges.insert({weight, {a,b}});
    }
    DisjointSetUnion::initialize(n+1);
    i1 answer = 1;
    for (auto i : alledges){
        answer *= exp(max(0,(int) (1 + maxedge - i.first)),((DisjointSetUnion::getSize(i.second.first) * DisjointSetUnion::getSize(i.second.second))-1),MOD);
        DisjointSetUnion::uniteSets(i.second.first, i.second.second);
        answer %= MOD;
    }
    cout << answer << "\n";


}
int main() {
    i1 t; cin >> t; for (i1 i =0  ; i < t; i++){
        solve();
    }
}
