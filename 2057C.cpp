#include <bits/stdc++.h>

using namespace std;

void solve() {
    int l,r; cin >> l >> r;
    int original = l;
    int originalr = r;
    int a(0), b(0), c(0);
    for (int i = 30; i >= 0; i--){
        if (r < (1 << i)){
            continue;
        }
        if (r&(1<<i) && (!(l&(1<<i)))){
            a += (1<<i);
            if (l == (1<<i)-1){
                b += (1<<i)-1;
                c += (1<<i)+1;
            }else {
                b += (1 << i) - 1;
                c += (1 << i) - 2;
            }
            break;
        }
        else if (r&(1<<i) && l&(1<<i)){
            r -= (1<<i);
            l -= (1<<i);
            a += (1<<i);
            b += (1<<i);
            c += (1<<i);
        }
    }
    cout << a << " " << b << " " << c << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}