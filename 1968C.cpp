#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n;
        cin >> n;
        int c = 501;
        cout << c << "\n";
        for (int i = 1; i < n; i++){
            int next;
            cin >> next;
            c += next;
            cout << c << "\n";
        }
    }
}