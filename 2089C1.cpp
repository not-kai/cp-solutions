#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long exp(long long x, long long n) {
    x %= MOD;  // note: m * m must be less than 2^63 to avoid ll overflow
    long long res = 1;
    while (n > 0) {
        if (n % 2 == 1) { res = res * x % MOD; }
        x = x * x % MOD;
        n /= 2;
    }
    return res;
}
long long inverse(long long x) {
    return exp(x, MOD - 2);
}
struct fraction{
    long long a,b;
};
fraction add(fraction x, fraction y){
    return fraction{((x.a *y.b)%MOD + ((y.a *x.b)%MOD))%MOD,(x.b*y.b)%MOD};
}
fraction multiply(fraction x, fraction y){
    return fraction{(x.a * y.a)%MOD, (x.b * y.b)%MOD};
}
void solve() {
    long long n,l,g; cin >> n >> l >> g;
    fraction arr[l+1][n];
    fraction sum[l+1];
    for (int i = 1; i <= l; i++){
        sum[i] = fraction{0,1};
    }
    arr[1][0] = fraction{1,1};
    for (int i = 1; i < n; i++){
        arr[1][i] = fraction{0,1};
    }
    for (int i = 0; i < n; i++){
        sum[1] = add(sum[1],arr[1][i]);
    }
    for (int i = 2; i <= l; i++){
        for (int j = 0; j < n; j++){
            arr[i][j] = fraction{0,1};
        }
        for (int j = 0; j< n; j++){
            arr[i][j] = add(arr[i][j],multiply(sum[i-1],fraction{i/n,1}));
            for (int k = 1; k <= (i%n+n)%n; k++){
                arr[i][j] = add(arr[i][j],arr[i-1][(((j-k)%n)+n)%n]);
            }
            if (j < (i%n+n)%n){
                arr[i][j] = add(arr[i][j], fraction{(i/n)+1,1});
            } else{
                arr[i][j] = add(arr[i][j], fraction{i/n,1});
            }
            arr[i][j] = multiply(arr[i][j], fraction{1,i});
        }
        for (int j = 0; j < n; j++){
            sum[i] = add(sum[i], arr[i][j]);
        }

    }
    for (int i = 0; i < n; i++){
        cout << (((arr[l][i].a * inverse(arr[l][i].b))%MOD)+MOD)%MOD << " ";
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
