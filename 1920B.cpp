#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n,k,x;
    cin >> n >> k >> x;
    vector<int> arr(n);
    int currans = 0;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++){
        if (i >= n-x){
            currans -= arr[i];
        } else{
            currans += arr[i];
        }
    }
    int finalans = currans;
    int timesremoved = 0;
    int currentright = n-1;
    int currentleft = n-x;
    while (timesremoved < k){
        if (currentleft == 0){
            while (timesremoved < k){
                timesremoved += 1;
                currans += arr[currentright];
                currentright -= 1;
                finalans = max(finalans, currans);
            }
        } else{
            timesremoved += 1;
            currans += arr[currentright];
            currans -= 2*arr[currentleft-1];
            currentright -= 1;
            currentleft -= 1;
            finalans = max(finalans, currans);
        }
    }
    cout << finalans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}