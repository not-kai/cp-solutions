#include <bits/stdc++.h>
using namespace std;
void solve() {
    int a,b,c; cin >> a >> b >> c;
    if ((a+b+c)%2 != 0){
        cout << -1 << "\n";
        return;
    } else if (c > a+b){
        cout << a+b << "\n";
    } else{
        cout << (a+b+c)/2 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0 ; i < t; i++){
        solve();
    }
}