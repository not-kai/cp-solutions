#include <bits/stdc++.h>
#define MOD 998244353
typedef long long i1;
using namespace std;
long long powersoftwo[200001];
void solve(){
    int n; cin >> n;
    i1 arr[n];
    for (i1 i = 0; i < n; i++){
        char temp; cin >> temp;
        arr[i] = temp - '0';
    }
    i1 answer = 1;
    i1 laststreak = 1;
    i1 lastnumber = arr[0];
    for (i1 i = 1; i < n; i++){
        if (arr[i] != lastnumber){
            laststreak = 1;
            lastnumber = arr[i];
        } else{
            laststreak += 1;
        }
        answer += powersoftwo[laststreak-1];
        answer %= MOD;
    }
    cout << answer << "\n";

}
int main() {
    powersoftwo[0] = 1;
    for (i1 i = 1; i <= 200000;  i++){
        powersoftwo[i] = powersoftwo[i-1]*2;
        powersoftwo[i] %= MOD;
    }
    i1 t; cin >> t; for (i1 i = 0; i < t; i++){
        solve();
    }
}
