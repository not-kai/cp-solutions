#include <bits/stdc++.h>
#define MOD 998244353
typedef long long i1;
using namespace std;
unordered_map<i1,i1> truepair;
#define sz(x) (int)(x).size()
#define ll long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef vector<int> vi;
const ll mod = (119 << 23) + 1, root = 62; // = 998244353
ll modpow(ll b, ll e) {
    ll ans = 1;
    for (; e; b = b * b % mod, e /= 2)
        if (e & 1) ans = ans * b % mod;
    return ans;
}
// For p < 2^30 there is also e.g. 5 << 25, 7 << 26, 479 << 21
// and 483 << 21 (same root). The last two are > 10^9.
typedef vector<ll> vl;
void ntt(vl &a) {
    int n = sz(a), L = 31 - __builtin_clz(n);
    static vl rt(2, 1);
    for (static int k = 2, s = 2; k < n; k *= 2, s++) {
        rt.resize(n);
        ll z[] = {1, modpow(root, mod >> s)};
        rep(i,k,2*k) rt[i] = rt[i / 2] * z[i & 1] % mod;
    }
    vi rev(n);
    rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k *= 2)
        for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
        ll z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
        a[i + j + k] = ai - z + (z > ai ? mod : 0);
        ai += (ai + z >= mod ? z - mod : z);
    }
}
vl conv(const vl &a, const vl &b) {
    if (a.empty() || b.empty()) return {};
    int s = sz(a) + sz(b) - 1, B = 32 - __builtin_clz(s), n = 1 << B;
    int inv = modpow(n, mod - 2);
    vl L(a), R(b), out(n);
    L.resize(n), R.resize(n);
    ntt(L), ntt(R);
    rep(i,0,n) out[-i & (n - 1)] = (ll)L[i] * R[i] % mod * inv % mod;
    ntt(out);
    return {out.begin(), out.begin() + s};
}
/*
struct HASH{
    size_t operator()(const pair<i1,i1>&x)const{
        return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
    }
};
unordered_map<pair<i1,i1>,i1,HASH> dp;
i1 grr(i1 object, i1 target){
    try{
        return dp.at({object, target});
    } catch(const exception& e){
        if (object == 1){
            dp[{object, target}] = truepair[target];
            return truepair[target];
        } else{
            i1 sum = 0;
            for (i1 i = 0; i <= target; i++) {
                if (object%2==0) {
                    sum += (grr(object / 2, i) * grr(object / 2, target - i)) % MOD;
                } else{
                    sum += (grr(object / 2, i) * grr((object+2) / 2, target - i)) % MOD;
                }
                sum %= MOD;
            }
            dp[{object, target}] = sum;
            return sum;
        }
    }
}
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i1 n, d; cin >> n >> d;
    vector<i1> digits(d);
    for (i1 i = 0; i < d; i++){
        cin >> digits[i];
    }
    multiset<i1> rah;
    for (i1 i = 0; i < d; i++){
        for (i1 j = 0; j < d; j++){
            rah.insert(digits[i]-digits[j]);
        }
    }
    i1 minelement = *rah.begin();
    for (i1 i : rah){
        truepair[i-minelement] += 1;
    }
    i1 target = -1 * minelement * (n/2);
    int maxdist = 0;
    for (auto i : truepair){
        if (i.first > maxdist){
            maxdist = i.first;
        }
    }
    vector<i1> polynomial(maxdist+1);
    for (int i = 0 ; i <= maxdist; i++){
        polynomial[i] = truepair[i];
    }
    vector<i1> grr = polynomial;
    vector<i1> series = {n/2};
    while (series[series.size()-1] != 1){
        if (series[series.size()-1]%2==0){
            series.push_back(series[series.size()-1]/2);
        } else{
            series.push_back(series[series.size()-1] - 1);
        }
    }
    for (int i = series.size()-1; i > 0; i--){
        if (series[i-1] == series[i]+1){
            vector<i1> newpoly(grr.size() + maxdist);
            for (int j = 0; j < newpoly.size(); j++){
                newpoly[j] = 0;
            }
            for (int j = 0; j < grr.size(); j++){
                for (int k = 0; k < polynomial.size(); k++){
                    newpoly[j+k] += (grr[j] * polynomial[k])%MOD;
                    newpoly[j+k] %= MOD;
                }
            }
            grr = newpoly;
        } else{
            vector<i1> grr2, grr3;
            grr2 = grr;
            grr3 = grr;
            grr = conv(grr2, grr3);
        }
    }
    cout << grr[target] << "\n";

}