#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    if (n == 1){
        cout << 0 << "\n";
        return;
    } if (n == 2){
        cout << 0 << " " << arr[0]%arr[1] + arr[1]%arr[0] << "\n";
        return;
    }
    set<int> grr;
    int firstmax = max(arr[1], arr[0]);
    int secondmax = min(arr[1], arr[0]);
    int ans = firstmax%secondmax + secondmax%firstmax;
    cout << 0 << " " << ans << " ";
    int stop = 2;
    if (firstmax == secondmax) {
        while (stop < n) {
            bool rawr = false;
            if (arr[stop] > firstmax) {
                firstmax = arr[stop];
                ans = max(firstmax % secondmax + secondmax % firstmax, ans);
                rawr = true;
            } else if (arr[stop] < firstmax) {
                secondmax = arr[stop];
                ans = max(firstmax % secondmax + secondmax % firstmax, ans);
                rawr = true;
            }
            cout << ans << " ";
            stop += 1;
            if (rawr) {
                break;
            }
        }
    }
    for (int i = stop; i < n; i++){
        if (arr[i] <= secondmax/2){
            cout << ans << " ";
        } else if (arr[i] <= secondmax){
            grr.insert(arr[i]);
            ans = max(ans, firstmax%arr[i] + arr[i]%firstmax);

            cout << ans << " ";
        }
        else if (arr[i] < firstmax){
            grr.insert(secondmax);
            secondmax = arr[i];
            ans = max(ans, firstmax%secondmax + secondmax%firstmax);
            while (!grr.empty() && (*grr.begin()<=secondmax/2)){
                ans = max(ans, firstmax%(*grr.begin()) + (*grr.begin())%firstmax);
                grr.erase(grr.begin());
            }
            cout << ans << " ";
        } else if (arr[i] == firstmax) {
            cout << ans << " ";
        }
        else{
            grr.insert(secondmax);
            secondmax = firstmax;
            firstmax = arr[i];
            ans = max(ans, firstmax%secondmax + secondmax%firstmax);
            while (!grr.empty() && (*grr.begin()<=secondmax/2)){
                ans = max(ans, firstmax%(*grr.begin()) + (*grr.begin())%firstmax);
                grr.erase(grr.begin());
            }
            auto sans = grr.begin();
            while (sans != grr.end() && *sans < firstmax/2){
                ans = max(ans, firstmax%(*sans) + (*sans)%firstmax);
                sans++;
            }
            cout << ans << " ";
        }
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0; i < t; i++){solve();}
}
