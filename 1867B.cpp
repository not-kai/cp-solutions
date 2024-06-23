#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        char temp; cin >> temp;
        arr[i] = temp - '0';
    }
    int workingpairs = 0;
    int badpairs = 0;
    for (int i = 0; i < n/2; i++){
        if (arr[i] == arr[n-i-1]){
            workingpairs += 1;
        } else{
            badpairs += 1;
        }
    }
    int maximum = workingpairs*2 + badpairs;
    if (n%2 == 1){
        maximum += 1;
    }
    for (int i = 0; i <= n; i++){
        if (i > maximum){
            cout << 0;
        }
        else if (i < badpairs){
            cout << 0;
        } else{
            if (n%2 == 1){
                cout << 1;
            } else{
                if ((i - badpairs) % 2 == 0){
                    cout << 1;
                } else{
                    cout << 0;
                }
            }
        }
    }
    cout << "\n";

}
int main() {
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}
