#include <bits/stdc++.h>

typedef long long i1;
using namespace std;

void solve() {
    i1 n; cin >> n;
    vector<i1> arr(n);
    i1 non1 = -1;
    for (i1 i = 0; i < n; i++){
        cin >> arr[i];
        if (arr[i] != 1 && arr[i] != -1){
            non1 = i;
        }
    }
    i1 minleft = 0;
    i1 maxleft = 0;
    i1 minright = 0;
    i1 maxright = 0;
    i1 curr = 0;
    for (i1 i = non1-1; i >= 0; i--){
        curr += arr[i];
        minleft = min(minleft, curr);
        maxleft = max(maxleft, curr);
    }
    curr = 0;
    for (i1 i = non1+1; i < n; i++){
        curr += arr[i];
        minright = min(minright, curr);
        maxright = max(maxright, curr);
    }
    i1 minwithx = minleft + minright + arr[non1];
    i1 maxwithx = maxleft + maxright + arr[non1];
    i1 minonlyleft = 0;
    i1 maxonlyleft = 0;
    i1 minonlyright = 0;
    i1 maxonlyright = 0;
    i1 currmax = 0;
    i1 currmin = 0;
    for (i1 i = 0; i < non1; i++){
        currmax += arr[i];
        currmin += arr[i];
        maxonlyleft = max(maxonlyleft, currmax);
        minonlyleft = min(minonlyleft, currmin);
        if (currmin > 0){
            currmin = 0;
        }
        if (currmax < 0){
            currmax = 0;
        }
    }
    currmax = 0;
    currmin = 0;
    for (i1 i = non1+1; i < n; i++){
        currmax += arr[i];
        currmin += arr[i];
        maxonlyright = max(maxonlyright, currmax);
        minonlyright = min(minonlyright, currmin);
        if (currmin > 0){
            currmin = 0;
        }
        if (currmax < 0){
            currmax = 0;
        }
    }
    set<i1> rah;
    if (non1 != -1) {
        for (i1 i = minwithx; i <= maxwithx; i++) {
            rah.insert(i);
        }
    }
    for (i1 i = minonlyleft; i <= maxonlyleft; i++){
        rah.insert(i);
    }
    for (i1 i = minonlyright; i <= maxonlyright; i++){
        rah.insert(i);
    }
    cout << rah.size() << "\n";
    for (i1 i : rah){
        cout << i << " ";
    }
    cout << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i1 t; cin >> t; for (i1 i = 0; i < t; i++){
        solve();
    }
}
