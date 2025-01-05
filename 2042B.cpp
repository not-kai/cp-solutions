#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    unordered_map<int,int> freq;
    for (int i = 0; i < n; i++){
        int temp; cin >> temp;
        freq[temp] += 1;
    }
    int singlecolor = 0;
    int doublecolor = 0;
    for (auto i : freq){
        if (i.second == 1){
            singlecolor += 1;
        } else{
            doublecolor += 1;
        }
    }
    cout << 2 * ((singlecolor+1)/2) + doublecolor << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}