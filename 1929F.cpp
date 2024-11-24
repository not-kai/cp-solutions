    #include <bits/stdc++.h>
    using namespace std;
    #define MAXN 500000
    #define MOD 998244353
    namespace CombinationMod{
        long long fac[MAXN + 1];
        long long inv[MAXN + 1];
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
        void factorial(long long p) {
            fac[0] = 1;
            for (int i = 1; i <= MAXN; i++) { fac[i] = fac[i - 1] * i % p; }
        }
        void inverses(long long p) {
            inv[MAXN] = exp(fac[MAXN], p - 2, p);
            for (int i = MAXN; i >= 1; i--) { inv[i - 1] = inv[i] * i % p; }
        }
        long long choose(long long n, long long r, long long p) {
            return fac[n] * inv[r] % p * inv[n - r] % p;
        }
    } //O(n+log(MOD), also has binary exponentiation with modulo in O(log(n))
    vector<pair<int,int>> tree;
    vector<int> preorder;
    void trees(int index){
        if (tree[index].first != -1){
            trees(tree[index].first);
        }
        preorder.push_back(index);
        if (tree[index].second != -1){
            trees(tree[index].second);
        }
    }
    void solve() {
        int n,c; cin >> n >> c;
        tree.clear();
        tree.resize(n+1);
        vector<int> values(n+1);
        for (int i = 1; i <= n; i++){
            int l,r; cin >> l >> r >> values[i];
            tree[i].first = l;
            tree[i].second = r;
        }
        preorder.clear();
        trees(1);
        vector<pair<int,int>> streaks;
        int low = 1;
        int currstreak = 0;
        for (int i = 0; i < n; i++){
            if (values[preorder[i]] == -1){
                currstreak += 1;
            } else{
                if (currstreak != 0){
                    streaks.push_back({currstreak,values[preorder[i]]-low});
                }
                currstreak = 0;
                low = values[preorder[i]];
            }
        }
        if (currstreak != 0){
            streaks.push_back({currstreak,c-low});
        }
        long long answer = 1;
        for (auto i : streaks){
            for (int j = 0; j < i.first; j++){
                answer *= (i.first+i.second-j);
                answer %= MOD;
            }
            answer *= CombinationMod::inv[i.first];
            answer %= MOD;
     
        }
        if (answer < 0){
            answer += MOD;
        }
        cout << answer << "\n";
     
     
     
     
    }
     
    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        CombinationMod::factorial(MOD);
        CombinationMod::inverses(MOD);
        int t; cin >> t; for (int i = 0; i < t; i++){
            solve();
        }
    }
