#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n,x,y; cin >> n >> x >> y;
    x -= 1;
    y -= 1;
    if (n == 3){
        cout << "0 1 2" << "\n"; return;
    }
    vector<int> ans(n,-1);
    if (n%2 == 0){
        if (x%2 == y%2){
            ans[x] = 1;
            ans[y] = 2;
            for (int i = 0; i < n; i++){
                if (ans[i] != -1){
                    continue;
                }
                if (i%2 == x%2){
                    ans[i] = 1;
                } else{
                    ans[i] = 0;
                }
            }
        } else{
            for (int i = 0; i < n; i++){
                if (i%2 == x%2){
                    ans[i] = 1;
                } else{
                    ans[i] = 0;
                }
            }
        }
    } else{
        ans[x] = 2;
        for (int i = x+1; i < n+x; i++){
            int trueindex = i%n;
            int previndex = (trueindex-1+n)%n;
            if (ans[previndex]){
                ans[trueindex] = 0;
            } else{
                ans[trueindex] = 1;
            }

        }
    }
    for (int i = 0; i < n; i++){
        cout << ans[i] << " ";
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
