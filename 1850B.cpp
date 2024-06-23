#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n; cin >> n;
    int answer = -1;
    int constestant = -1;
    for (int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        if (a <= 10){
            if (b > answer){
                answer = b;
                constestant = i+1;
            }
        }
    }
    cout << constestant << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}
