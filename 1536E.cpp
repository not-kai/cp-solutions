#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long powersoftwo[4000001];
void solve() {
    int n,m; cin >> n >> m;
    int arr[n][m];
    bool fullgrid = true;
    int totalsum = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            char temp; cin >> temp;
            if (temp == '0'){
                fullgrid = false;
                arr[i][j] = 0;
            } else{
                totalsum += 1;
                arr[i][j] = 1;
            }
        }
    }
    if (fullgrid){
        cout << powersoftwo[totalsum]-1 << "\n";
    } else{
        cout << powersoftwo[totalsum] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    powersoftwo[0] = 1;
    for (int i = 1; i <= 4000000; i++){
        powersoftwo[i] = (2*powersoftwo[i-1])%MOD;
    }
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}