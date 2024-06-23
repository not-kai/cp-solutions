#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n; cin >> n;
    vector<pair<int,int>> arr(n);
    for (int i=  0; i < n; i++){
        cin >> arr[i].first;
        arr[i].second = i+1;
    }
    sort(arr.begin(), arr.end());
    int currdivisor = arr[0].first;
    queue<pair<int,int>> operations;
    for (int i = 1; i < n; i++){
        if (arr[i].first%currdivisor == 0){
            currdivisor = arr[i].first;
            continue;
        }
        if (currdivisor > arr[i].first){
            operations.push({i, currdivisor-arr[i].first});
            continue;
        } else{
            operations.push({i, currdivisor-(arr[i].first%currdivisor)});
            currdivisor = arr[i].first+currdivisor-(arr[i].first%currdivisor);
        }
        /*
        if (arr[i] <= currdivisor*2){
            operations.push({i-1, arr[i]-currdivisor});
            currdivisor = arr[i];
        } else{
            operations.push({i-1, arr[i]%currdivisor});
            currdivisor = arr[i] + (arr[i]%currdivisor);
        }
         */
    }
    cout << operations.size() << "\n";
    while (!operations.empty()){
        cout << (arr[operations.front().first].second) << " " << operations.front().second << "\n";
        operations.pop();
    }
}
int main() {
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}
