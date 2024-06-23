#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n; cin >> n;
    int positive;
    if (n%2 == 0){
        positive = (n/2);
    } else{
        positive = (n/2)+1;
    }
    if ((n - positive) % 2 != 0){
        positive += 1;
    }
    int currpositive = 0;
    for (int i = 0; i < n; i++){
        int temp; cin >> temp;
        if (temp == 1){
            currpositive += 1;
        }
    }
    if ((n-currpositive)%2 == 0) {
        cout << max(0, positive - currpositive) << "\n";
    } else{
        cout << max(1, positive-currpositive) << "\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}
