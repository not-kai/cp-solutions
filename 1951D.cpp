#include <bits/stdc++.h>

typedef long long i;
using namespace std;
void solve() {
    i n,k; cin >> n >> k;
    vector<i> shops;
    while (k != 0){
        if (n > k && k > (n+2-(n%2))/2){
            cout << "NO" << "\n";
            return;
        }
        else if (k < (n+2-(n%2))/2 && k > (n+4-(n%4))/4){
            shops.push_back(n-(k-1));
            shops.push_back(1);
            break;
        } else if (n == k){
            shops.push_back(1);
            break;
        } else if (k > n){
            cout << "NO" << "\n";
            return;
        } else{
            k -= 1;
            if (n%2 == 0){
                shops.push_back((n/2)+1);
                n >>= 1;
                n -= 1;
            } else{
                shops.push_back((n+1)/2);
                n >>= 1;

            }
        }
    }
    cout << "YES" << "\n";
    cout << shops.size() << "\n";
    for (i shop : shops){
        cout << shop << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i t; cin >> t; for (i i = 0; i < t; i++){
        solve();
    }
}