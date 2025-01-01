    #include <bits/stdc++.h>
     
    typedef long long i1;
    using namespace std;
     
    void solve() {
        i1 n; cin >> n;
        vector<pair<i1,i1>> arr(n);
        for (i1 i = 0; i < n; i++){
            cin >> arr[i].first;
        }
        for (i1 i = 0; i < n; i++){
            cin >> arr[i].second;
        }
        i1 maxanswer = INT_MIN;
        for (i1 s = 0; s < n; s++){
            i1 curranswer = arr[s].first + arr[s].second;
            for (i1 i = 0; i < n; i++){
                if (i == s){
                    continue;
                }
                if (arr[i].first > arr[i].second){
                    curranswer += arr[i].first;
                } else{
                    curranswer += arr[i].second;
                }
            }
            maxanswer = max(maxanswer, curranswer);
        }
        cout << maxanswer << "\n";
     
    }
     
    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        i1 t; cin >> t; for (i1 i = 0; i < t; i++){
            solve();
        }
    }
