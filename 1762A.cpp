#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n; cin >> n;
    int arr[n];
    int odd = 0;
    int even = 0;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        if (arr[i]%2 == 1){
            odd+=1;
        } else{
            even += 1;
        }
    }
    if (odd%2 == 0){
        cout << 0 << "\n";
    } else{
        int minimum = INT_MAX;
        for (int i = 0; i < n; i++){
            if (arr[i]%2 == 0){
                int temp = 0;
                while (arr[i]%2 == 0){
                    arr[i] /= 2;
                    temp += 1;
                }
                minimum = min(minimum, temp);
                continue;
            }
            int temp = 0;
            while (arr[i]%2 == 1){
                arr[i] -= 1;
                arr[i] /= 2;
                temp += 1;
            }
            minimum = min(minimum, temp);
        }
        cout << minimum << "\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0; i < t; i++ ){
        solve();
    }
}
