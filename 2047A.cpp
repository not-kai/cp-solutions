    #include <bits/stdc++.h>
     
    using namespace std;
     
    void solve() {
        int n; cin >> n;
        vector<int> arr(n);
        int ans = 0;
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }
        int curr = 0;
        for (int i = 0; i < n; i++){
            curr += arr[i];
            if (((int)round(sqrt(curr))) * ((int)round(sqrt(curr))) == curr && (int) round(sqrt(curr))%2 == 1){
                ans += 1;
            }
        }
        cout << ans << "\n";
    }
     
    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int t; cin >> t; for (int i = 0; i < t; i++){
            solve();
        }
    }
