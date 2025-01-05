#include <bits/stdc++.h>

using namespace std;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); } //O(log(ab)) from euler probably
int lcm(int a, int b) { return a*b/gcd(a,b); } //O(log(ab))
void solve() {
    int a,b; cin >> a >> b;
    if (a > b){
        swap(a,b);
    }
    cout << lcm(a,b) << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}