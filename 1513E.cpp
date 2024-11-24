    #include <bits/stdc++.h>
    #define MAXN 200000
    #define MOD 1000000007
    typedef long long i1;
    using namespace std;
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
            for (i1 i = 1; i <= MAXN; i++) { fac[i] = fac[i - 1] * i % p; }
        }
        void inverses(long long p) {
            inv[MAXN] = exp(fac[MAXN], p - 2, p);
            for (i1 i = MAXN; i >= 1; i--) { inv[i - 1] = inv[i] * i % p; }
        }
        long long choose(long long n, long long r, long long p) {
            return fac[n] * inv[r] % p * inv[n - r] % p;
        }
    } //O(n+log(MOD), also has binary exponentiation with modulo in O(log(n))
     
    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        i1 n; cin >> n ; vector<i1> arr(n);
        i1 sum = 0;
        for (i1 i = 0; i < n; i++){
            cin >> arr[i];
            sum += arr[i];
        }
        i1 mean = sum/n;
        if (mean*n != sum){
            cout << 0 << "\n";
            return 0;
        }
        CombinationMod::factorial(MOD);
        CombinationMod::inverses(MOD);
        unordered_map<i1,i1> less;
        unordered_map<i1,i1> greater;
        i1 lessthan = 0;
        i1 greaterthan = 0;
        i1 equal = 0;
        for (i1 i = 0; i < n; i++){
            if (arr[i] < mean){
                lessthan += 1;
                less[arr[i]] += 1;
            } else if (arr[i] > mean){
                greaterthan += 1;
                greater[arr[i]] += 1;
            } else{
                equal += 1;
            }
        }
        if (lessthan <= 1 || greaterthan <= 1){
            i1 answer = 1;
            i1 numberofstuff = 0;
            for (auto i : less){
                answer *= CombinationMod::choose(numberofstuff+i.second,i.second,MOD);
                answer %= MOD;
                numberofstuff += i.second;
            }
            for (auto i : greater){
                answer *= CombinationMod::choose(numberofstuff+i.second,i.second,MOD);
                answer %= MOD;
                numberofstuff += i.second;
            }
            answer *= CombinationMod::choose(numberofstuff+equal,equal,MOD);
     
            answer %= MOD;
            cout << answer << "\n";
        } else{
            i1 answer = 2;
            i1 left = 1;
            i1 right = 1;
            i1 numberofstuff = 0;
            for (auto i : less){
                left *= CombinationMod::choose(numberofstuff+i.second,i.second,MOD);
                left %= MOD;
                numberofstuff += i.second;
            }
            numberofstuff = 0;
            for (auto i : greater){
                right *= CombinationMod::choose(numberofstuff+i.second,i.second,MOD);
                right %= MOD;
                numberofstuff += i.second;
            }
            answer *= left*right;
            answer %= MOD;
            answer *= CombinationMod::choose(n,equal,MOD);
            answer %= MOD;
            cout << answer <<"\n";
     
        }
     
     
    }
