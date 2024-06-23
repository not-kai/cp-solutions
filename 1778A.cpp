#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n; cin >> n;
    int sum = 0;
    int twoinarow = 0;
    int onlyones = 1;
    int lastelement = 0;
    for (int i = 0; i < n; i++){
        int temp; cin >> temp;
        sum += temp;
        if (temp == -1 && lastelement == -1){
            twoinarow = 1;
        }
        if (temp == -1){
            onlyones = 0;
        }
        lastelement = temp;
    }
    if (twoinarow){
        sum += 4;
    } else if (onlyones){
        sum -= 4;
    }
    cout << sum << "\n";
}
int main() {
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}
