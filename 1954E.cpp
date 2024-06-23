#include <bits/stdc++.h>

typedef long long i1;
using namespace std;
void solve() {

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i1 n; cin >> n;
    vector<i1> arr(n);
    i1 maxelement = 0;
    for (i1 i = 0 ; i < n; i++){
        cin >> arr[i];
        maxelement = max(maxelement, arr[i]);
    }
    vector<i1> allanswers;
    i1 curranswer = 0;
    vector<pair<i1,i1>> streaks;
    i1 start = 0;
    i1 streak = 1;
    for (i1 i = 1; i < n; i++){
        if (arr[i] > arr[i-1]){
            streak += 1;
        } else{
            streaks.push_back({start, streak});
            streak = 1;
            start = i;
        }
    }
    if (start != n) {
        streaks.push_back({start, streak});
    }
    vector<i1> subtracted;
    vector<i1> added;
    curranswer += arr[0];
    for (auto i : streaks){
        curranswer += arr[i.first+i.second-1] - arr[i.first];
        if (i.second != 1){
            added.push_back(i.first+i.second-1);
            subtracted.push_back(i.first);
        }
    }
    if (added.empty() || added[0] != 0){
        added.push_back(0);
    }
    vector<i1> changes(maxelement+1);
    for (i1 i = 0; i <= maxelement; i++){
        changes[i] = 0;
    }
    for (i1 asdasd : subtracted){
        i1 actualnumber = arr[asdasd];
        vector<pair<i1,i1>> rah;
        for (i1 i = 1; i <= ceil(sqrt(actualnumber)); i++){
            if (actualnumber%i == 0) {
                rah.push_back({actualnumber / i, i});
            } else{
                rah.push_back({1+(actualnumber/i),i});
            }
        }
        for (i1 i = sqrt(actualnumber); i >= 1; i--){
            if (actualnumber%i == 0) {
                rah.push_back({i, actualnumber/i});
            } else{
                rah.push_back({i,1+(actualnumber/i)});
            }
        }
        for (i1 i = 1; i < rah.size(); i++){
            changes[rah[i].second] += (rah[i-1].first - rah[i].first);
        }
    }
    for (i1 asdasd : added){
        i1 actualnumber = arr[asdasd];
        vector<pair<i1,i1>> rah;
        for (i1 i = 1; i <= ceil(sqrt(actualnumber)); i++){
            if (actualnumber%i == 0) {
                rah.push_back({actualnumber / i, i});
            } else{
                rah.push_back({1+(actualnumber/i),i});
            }
        }
        for (i1 i = sqrt(actualnumber); i >= 1; i--){
            if (actualnumber%i == 0) {
                rah.push_back({i, actualnumber/i});
            } else{
                rah.push_back({i,1+(actualnumber/i)});
            }
        }
        for (i1 i = 1; i < rah.size(); i++){
            changes[rah[i].second] -= (rah[i-1].first - rah[i].first);
        }
    }
    for (i1 i = 1; i <= maxelement; i++){
        curranswer += changes[i];
        cout << curranswer << " ";
    }
    cout << "\n";



}