#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n, k; cin >> n >> k;
    if (n%k != 0){
        cout << 1 << "\n" << n << "\n";
    } else{
        cout << 2 << "\n" << n-1 << " " << 1 << "\n";
    }
}
int main() {
    int testcases;
    cin >> testcases;
    for (int i = 0; i < testcases; i++){
        solve();
    }
}
