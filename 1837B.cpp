#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n; cin >> n;
    char current;
    cin >> current;
    int maxstreak = 1;
    int currentstreak = 1;
    for (int i = 0; i < n-1; i++){
        char temp;
        cin >> temp;
        if (temp != current){
            currentstreak = 1;
            current = temp;
        } else{
            currentstreak += 1;
            maxstreak = max(maxstreak, currentstreak);
        }
    }
    cout << maxstreak+1 << "\n";
}
int main() {
    int testcases; cin >> testcases; for (int i = 0; i < testcases; i++){
        solve();
    }
}
