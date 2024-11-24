    #include <bits/stdc++.h>
     
    using namespace std;
     
    void solve() {
        int n;
        cin >> n;
        vector<long long> arr(n);
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }
        long long left = 1;
        long long right = 1e12;
        long long maxmin = 1;
        while (left <= right){
            long long mid = (left+right)/2;
            long long keep = 0;
            bool works = true;
            for (int i = 0; i < n; i++){
                if (arr[i] - mid >= 0){
                    keep += arr[i] - mid;
                } else{
                    keep -= mid - arr[i];
                } if (keep < 0){
                    works = false;
                    break;
                }
            }
            if (works){
                maxmin = max(mid, maxmin);
                left = mid+1;
            } else{
                right = mid-1;
            }
        }
        left = maxmin;
        right = 1e12;
        long long minmax = 1e12;
        while (left <= right){
            long long mid = (left+right)/2;
            long long stored = 0;
            for (int i =0; i < n; i++){
                if (arr[i] - mid >= 0){
                    stored += arr[i] - mid;
                } else{
                    stored -= mid - arr[i];
                    stored = max(stored, 0LL);
                }
            }
            if (stored <= 0){
                minmax = min(mid,minmax);
                right = mid-1;
            } else{
                left = mid+1;
            }
        }
        cout << minmax - maxmin << "\n";
    }
     
    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int t; cin >> t; for (int i = 0; i < t ;i++){
            solve();
        }
    }
