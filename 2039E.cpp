#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = 1000000;
    vector<long long> noextend(n+1,0);
    vector<long long> prefix(n+1,0);
    vector<long long> prefix2(n+1, 0);
    vector<long long> answers(n+1,0);
    answers[2] = 1;
    for (long long i = 3; i <= n; i++) {
        long long negative1 = 1;
        long long zero = 1;
        long long one = i-3;
        long long contr = (i-2)*(i-1)/2;
        contr %= MOD;
        contr -= 1;
        contr %= MOD;
        long long totalnoext = (((contr + i*prefix[i-1])%MOD) - prefix2[i-1])%MOD;
        noextend[i] = totalnoext;
        prefix[i] = (prefix[i-1] + noextend[i])%MOD;
        prefix2[i] = (prefix2[i-1] + prefix[i])%MOD;
        answers[i] = (((totalnoext + zero)%MOD) + ((((negative1 + one)%MOD) + prefix[i-1])%MOD))%MOD;
    }
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        int q; cin >> q; cout << (MOD+answers[q])%MOD << "\n";
    }

}
