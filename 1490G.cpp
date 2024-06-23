#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,q; cin >> n >> q;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int queries[q];
    for (int i = 0; i < q; i++){
        cin >> queries[i];
    }
    long long prefixsum[n];
    prefixsum[0] = arr[0];
    set<long long> maxprefixes = {arr[0]};
    unordered_map<long long,int> firstinstance;
    for (int i = 1; i < n; i++){
        prefixsum[i] = prefixsum[i-1]+arr[i];
        maxprefixes.insert({prefixsum[i],0});
    }
    for (int i = 0; i < n; i++){
        firstinstance[prefixsum[i]] = n;
    }
    for (int i = 0; i < n; i++){
        firstinstance[prefixsum[i]] = min(firstinstance[prefixsum[i]], i);
    }
    vector<long long> sortedmaxprefixes(maxprefixes.size());
    int ihatethis = 0;
    for (long long i : maxprefixes){
        sortedmaxprefixes[ihatethis] = i;
        ihatethis++;
    }
    int minmaxprefixes[maxprefixes.size()];
    minmaxprefixes[maxprefixes.size()-1] = firstinstance[sortedmaxprefixes[sortedmaxprefixes.size()-1]];
    for (int i = sortedmaxprefixes.size()-2; i >= 0; i--){
        minmaxprefixes[i] = min(minmaxprefixes[i+1], firstinstance[sortedmaxprefixes[i]]);
    }
    for (int query : queries) {
        if (prefixsum[n - 1] <= 0 && *maxprefixes.rbegin() < query) {
            cout << -1 << " ";
            continue;
        } else if (prefixsum[n-1] <= 0){
            auto iter = lower_bound(sortedmaxprefixes.begin(), sortedmaxprefixes.end(), query);
            cout << minmaxprefixes[iter-sortedmaxprefixes.begin()] << " ";
            continue;
        }
        long long answer = 0;
        long long currn = 0;
        currn += ((long long) ((max(0LL, query - *maxprefixes.rbegin())) / prefixsum[n - 1])) * ((long long) prefixsum[n - 1]);
        answer += ((long long) n) * ((long long)((max(0LL, query - *maxprefixes.rbegin())) / prefixsum[n - 1]));
        if (currn + *maxprefixes.rbegin() >= query) {
            auto iter = lower_bound(sortedmaxprefixes.begin(), sortedmaxprefixes.end(), query-currn);
            cout << answer + minmaxprefixes[iter-sortedmaxprefixes.begin()] << " ";
            continue;
        }
        currn += prefixsum[n - 1];
        answer += n;
        auto iter = lower_bound(sortedmaxprefixes.begin(), sortedmaxprefixes.end(), query-currn);
        cout << answer + minmaxprefixes[iter-sortedmaxprefixes.begin()] << " ";
    }
    cout << "\n";

}
int main() {
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}