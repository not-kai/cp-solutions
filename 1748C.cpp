#include <bits/stdc++.h>

typedef long long i1;
using namespace std;
void solve(){
    int n; cin >> n;
    i1 originalarr[n]; for (i1 i = 0; i < n; i++){
        cin >> originalarr[i];
    }
    i1 prefixarr[n];
    prefixarr[0] = originalarr[0];
    for (i1 i = 1; i < n; i++){
        prefixarr[i] = prefixarr[i-1] + originalarr[i];
    }
    set<i1> occuranceofzeros;
    for (i1 i = 0; i < n; i++){
        if (originalarr[i] == 0){
            occuranceofzeros.insert(i);
        }
    }
    occuranceofzeros.insert(n);
    i1 answer = 0;
    for (i1 i = 0; i < *occuranceofzeros.begin(); i++){
        if (prefixarr[i] == 0){
            answer += 1;
        }
    }
    for (auto iter = occuranceofzeros.begin(); *iter != n; iter++){
        i1 maxanswer = 1;
        i1 firstvalue = *iter;
        iter++;
        set<i1> valuessofar;
        map<i1,i1> occurances;
        for (i1 i = firstvalue; i < *iter; i++){
            occurances[prefixarr[i]] += 1;
            if (occurances[prefixarr[i]] == 1){
                valuessofar.insert(prefixarr[i]);
            }
        }
        i1 valueused = -1;
        for (i1 i : valuessofar){
            if (occurances[i] > maxanswer) {
                valueused = i;
                maxanswer = max(maxanswer, occurances[i]);
            }
        }
        answer += maxanswer;
        iter--;
    }
    cout << answer << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i1 t; cin >> t; for (i1 i = 0; i < t; i++){
        solve();
    }
}
