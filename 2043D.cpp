#include <bits/stdc++.h>

using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); } //O(log(ab)) from euler probably
void solve() {
    long long l,r,g; cin >> l >> r >> g;
    long long truel, truer;
    if (g == 1){
        truel = l;
        truer = r;
    } else {
        if (l % g == 0) {
            truel = l / g;
        } else {
            truel = (l / g) + 1;
        }
        truer =(r/g);
    }
    if (truel > truer){
        cout << -1 << " " << -1 << "\n";
        return;
    }
    long long diff = 0;
    long long currb = truer;
    while (gcd(currb, truel) != 1){
        currb -= 1;
        diff += 1;
        if (currb < truel || currb < 0){
            cout << -1 << " " << -1 << "\n";
            return;
        }
    }
    long long ansa = truel; long long ansb = currb;
    for (long long i = truel; i <= truel + diff; i++){
        if (i > truer){
            break;
        }
        bool works = true;
        long long b = truer;
        while (gcd(b, i) != 1){
            b -= 1;
            if (b < truel || b < i){
                works = false;
                break;
            }
            if (b - i <= ansb - ansa){
                works = false;
                break;
            }
        }
        if (works) {
            if (b - i > ansb - ansa) {
                ansa = i;
                ansb = b;
            } else if (b - i == ansb - ansa && i < ansa){
                ansa = i;
                ansb = b;
            }
        }
    }
    cout << ansa*g << " " << ansb*g << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}
