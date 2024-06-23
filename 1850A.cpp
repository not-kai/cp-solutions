#include <bits/stdc++.h>
using namespace std;
void solve(){
    int a,b,c;
    cin >> a >> b >> c;
    if ((a+b>=10) || (a+c>=10) || (b+c>=10)){
        cout << "YES" << "\n";
    } else{
        cout << "NO" << "\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}
