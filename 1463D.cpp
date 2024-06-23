#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n; cin >> n;
    int arr[n];
    set<int> allnumbers;
    for (int i = 1; i <= 2*n; i++){
        allnumbers.insert(i);
    }
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        allnumbers.erase(arr[i]);
    }
    set<int> findallmin = allnumbers;
    set<int> findallmax = allnumbers;
    int maxmin = 0;
    int maxmax = 0;
    for (int i = 0; i < n; i++){
        auto iter = findallmin.lower_bound(arr[i]);
        if (iter == findallmin.end()){
            findallmin.erase(*findallmin.begin());
        } else{
            findallmin.erase(*iter);
            maxmin += 1;
        }
    }

    for (int i = n-1; i >= 0; i--){
        auto iter = findallmax.lower_bound(arr[i]);
        if (iter == findallmax.begin()){
            findallmax.erase(*findallmax.rbegin());
        } else{
            iter--;
            findallmax.erase(*iter);
            maxmax += 1;
        }
    }

    maxmin = n - maxmin;
    cout << abs(maxmin-maxmax)+1 << "\n";


}
int main() {
    int t; cin >> t; for (int i = 0; i <t; i++){
        solve();
    }
}
