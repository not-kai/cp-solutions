#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,m;
    vector<int> arr;
    cin >> n >> m;
    set<int> instancesofzero;
    set<int> instancesofone;
    set< pair<int, int>> answer;
    for (int i = 0; i < n; i++){
        char temp; cin >> temp;
        if (temp=='0'){
            arr.push_back(0);
        } else{
            arr.push_back(1);
        }
        if (arr[i] == 0){
            instancesofzero.insert(i);
        } else{
            instancesofone.insert(i);
        }
    }
    for (int i = 0; i < m; i++){
        int a,b; cin >> a >> b;
        a-= 1;
        b-=1;
        auto randompointer = instancesofone.lower_bound(a);
        int truea, trueb;
        if (randompointer == instancesofone.end()){
            answer.insert({-1,-1});
            continue;
        } else if (*randompointer > b){
            answer.insert({-1,-1});
            continue;
        } else{
            truea = *randompointer;
        }

        auto randompointer2 = instancesofzero.upper_bound(b);
        if (randompointer2 == instancesofzero.begin()){
            answer.insert({-1,-1});
            continue;
        } else{
            randompointer2--;
            if (*randompointer2 < a){
                answer.insert({-1,-1});
                continue;
            } else{
                trueb = *randompointer2;
            }
        }
        if (truea > trueb){
            answer.insert({-1,-1});
            continue;
        }
        answer.insert({truea, trueb});
    }
    cout << answer.size() << "\n";


}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}
