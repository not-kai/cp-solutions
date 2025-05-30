#include <bits/stdc++.h>

typedef long long i1;
using namespace std;

void solve() {
    i1 n; cin >> n;
    vector<i1> arr(n);
    i1 one = 0;
    i1 odd = 0;
    i1 indicies = 0;
    for (i1 i = 0; i < n; i++){
        char temp; cin >> temp;
        if (temp == 'B'){
            arr[i] = 0;
        } else{
            arr[i] = 1;
            one += 1;
            if (i%2==1){
                odd += 1;
            }
            indicies += i;
        }
    }
    i1 needodd;
    if (one%2==0){
        needodd = one/2;
    } else{
        if ((n-1)%2==1){
            needodd = (one+1)/2;
        } else{
            needodd = one/2;
        }
    }
    i1 needindicies = 0;
    for (i1 i = n-one; i < n; i++){
        needindicies += i;
    }
    i1 ans = abs(needodd - odd);
    ans += (needindicies-indicies - abs(needodd-odd))/2;
    cout << ans << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i1 t; cin >> t; for (i1 i = 0; i < t; i++){
        solve();
    }
}
