#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> truearr(n);
    vector<int> arr;
    int truemax = -1;
    for (int i = 0; i < n; i++){
        char temp; cin >> temp;
        truearr[i] = temp - 'a';
        truemax = max(truemax, truearr[i]);
        if (arr.empty()){
            arr.push_back(truearr[i]);
        } else{
            if (arr[arr.size()-1] != truearr[i]){
                arr.push_back(truearr[i]);
            }
        }
    }
    if (n == 1){
        cout << 0 << "\n";
        return;
    }
    vector<pair<int,int>> maximums; //index, how big it is
    for (int i = 0; i < truearr.size(); i++){
        if (maximums.empty()){
            maximums.push_back({i,truearr[i]});
        } else{
            while (!maximums.empty() && (*maximums.rbegin()).second< truearr[i]){
                maximums.pop_back();
            }
            maximums.push_back({i,truearr[i]});
        }
    }
    for (int i = 0; i < maximums.size()/2; i++){
        swap(truearr[maximums[i].first], truearr[maximums[maximums.size()-1-i].first]);
    }
    bool flag = true;
    for (int i = 1; i < truearr.size(); i++){
        if (truearr[i] < truearr[i-1]){
            flag = false;
            break;
        }
    }
    if (flag){
        int lastmax = -1;
        for (int i = 0; i < maximums.size(); i++){
            if (maximums[i].second == truemax){
                lastmax = i;
            }
        }
        cout << maximums.size()-1-lastmax << "\n";
    } else{
        cout << -1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}