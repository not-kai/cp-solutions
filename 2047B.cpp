    #include <bits/stdc++.h>
     
    using namespace std;
     
    void solve() {
        int n; cin >> n;
        vector<char> arr(n);
        unordered_map<char,int> freq;
        unordered_map<char,int> occ;
        unordered_map<int,vector<char>> charwithfreq;
        for (int i = 0; i < n; i++){
            cin >> arr[i];
            freq[arr[i]] += 1;
            occ[arr[i]] = i;
        }
        for (char i = 'a'; i <= 'z'; i++){
            charwithfreq[freq[i]].push_back(i);
        }
        pair<char,int> mostcommon({0,0}), leastcommon({0,9999999});
        for (char i = 'a'; i <= 'z'; i++){
            if (freq[i] > mostcommon.second){
                mostcommon = {i, freq[i]};
            }
            if (freq[i] < leastcommon.second && freq[i] != 0){
                leastcommon = {i, freq[i]};
            }
        }
        if (leastcommon == mostcommon){
            for (char i : charwithfreq[leastcommon.second]){
                if (i != mostcommon.first){
                    arr[occ[i]] = mostcommon.first;
                    break;
                }
            }
        }else {
            arr[occ[leastcommon.first]] = mostcommon.first;
        }
        for (char i : arr){
            cout << i;
        }
        cout << "\n";
     
     
    }
     
    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int t; cin >> t; for (int i = 0 ; i < t ;i++){
            solve();
        }
    }
