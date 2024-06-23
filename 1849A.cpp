#include <bits/stdc++.h>
using namespace std;
void solve(){
    int b, c, h;
    cin >>  b >> c >> h;
    if (b-1 > c+h){
        cout << c+h+c+h+1;
    } else{
        cout << b+b-1;
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
