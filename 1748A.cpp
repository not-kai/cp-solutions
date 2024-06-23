#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n; cin >> n;
    if (n%2 == 0){
        n -= 1;
    }
    cout << (n/2)+1 << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}
