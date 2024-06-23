#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n,x; cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int maxk = -1;
    vector<int> rah;
    for (int i = 0; i < n; i++){
        rah.push_back(i);
    }
    for (int i = 30; i >= 0; i--){
        if (!(x >> i & 1)){ //0, you have to block
            vector<int> newrah;
            vector<int> finalrah;
            int numberofnums = 0;
            for (int j = 0; j < n; j++){
                if (arr[j] >> i & 1){
                    numberofnums += 1;
                }
                if (numberofnums%2 == 0){
                    newrah.push_back(j);
                }
            }
            if (numberofnums%2 == 1){
                break;
            }
            int pointer1 = 0;
            int pointer2 = 0;
            while (pointer1 < rah.size() && pointer2 < newrah.size()){
                if (rah[pointer1] == newrah[pointer2]){
                    finalrah.push_back(rah[pointer1]);
                    pointer1 += 1;
                    pointer2 += 1;
                } else if (rah[pointer1] > newrah[pointer2]){
                    pointer2 += 1;
                } else{
                    pointer1 += 1;
                }
            }
            rah = finalrah;
            if (i == 0){
                maxk = max(maxk, (int) rah.size());
            }
        } else{ //1, you can choose to block or end
            if (i == 0){
                maxk = max(maxk, (int) rah.size());
                break;
            }
            vector<int> newrah;
            vector<int> finalrah;
            int numberofnums = 0;
            for (int j = 0; j < n; j++){
                if (arr[j] >> i & 1){
                    numberofnums += 1;
                }
                if (numberofnums%2 == 0){
                    newrah.push_back(j);
                }
            }
            int pointer1 = 0;
            int pointer2 = 0;
            while (pointer1 < rah.size() && pointer2 < newrah.size()){
                if (rah[pointer1] == newrah[pointer2]){
                    finalrah.push_back(rah[pointer1]);
                    pointer1 += 1;
                    pointer2 += 1;
                } else if (rah[pointer1] > newrah[pointer2]){
                    pointer2 += 1;
                } else{
                    pointer1 += 1;
                }
            }
            if (numberofnums%2 == 0) {
                maxk = max(maxk, (int) finalrah.size());
            }
        }
    }
    if (maxk == 0){
        cout << -1 << "\n";
    } else{
        cout << maxk << "\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}