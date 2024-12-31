#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n,d; cin >> n >> d;
    vector<int> answer;
    answer.push_back(1);
    if (d%3 == 0 || n >= 3){
        answer.push_back(3);
    }
    if (d%5== 0){
        answer.push_back(5);
    }
    if (d%7 == 0 || n >= 3){
        answer.push_back(7);
    }
    if (d%9 == 0 || (d%3 == 0 && n>=3) || (n>=6)){
        answer.push_back(9);
    }
    for (int i : answer){
        cout << i << " ";
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
