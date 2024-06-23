#include <bits/stdc++.h>

using namespace std;
vector<vector<pair<short,short>>> rah(19);
vector<bool> init(19);
vector<pair<short,short>> somethingrecursion(int n) { //creates {n,n,n,n,n,...}
    if (init[n]){
        return rah[n];
    }
    if (n == 1){
        return {{0,0}};
    } if (n == 2){
        return {{0,0},{0,1}};
    } else{
        vector<pair<short,short>> curr;
        for (int i = n-1; i >= 1; i--){
            if (i != n-1){
                curr.push_back({0,i-1});
            }
            for (auto i : somethingrecursion(i)){
                curr.push_back(i);
            }
        }
        curr.push_back({0,n-1});
        rah[n] = curr;
        init[n] = true;
        return curr;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i <= 18; i++){
        rah[i] = {};
        init[i] = false;
    }
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    long long maxanswer = 0;
    int mymax = 0;
    for (int i = 0; i < (1 << n); i++){
        long long total = 0;
        int onestreak = 0;
        for (int j = 0; j < n; j++){
            if (1 & (i >> j)){
                onestreak += 1;
            } else{
                total += onestreak*onestreak;
                onestreak = 0;
                total += arr[j];
            }
        }
        total += onestreak*onestreak;
        if (total > maxanswer){
            maxanswer = total;
            mymax = i;
        }
    }
    vector<pair<int,int>> streaks;
    int onestreak=0;
    int startstreak = 0;
    for (int j = 0; j < n; j++){
        if (1 & (mymax >> j)){
            onestreak += 1;
        } else{
            streaks.push_back({startstreak, onestreak});
            startstreak = j+1;
            onestreak = 0;
        }
    }
    vector<pair<short,short>> operations;
    streaks.push_back({startstreak, onestreak});
    for (auto i : streaks){
        if (i.second == 0){
            continue;
        }
        for (int k = i.first+1; k <= i.first+i.second; k++){
            if (arr[k-1] != 0) {
                operations.push_back({k, k});
            }
        }
        for (auto j : somethingrecursion(i.second)){
            operations.push_back({j.first + i.first + 1, j.second + i.first + 1});
        }
    }
    cout << maxanswer << " " << operations.size() <<  "\n";
    for (auto i : operations){
        cout << i.first << " " << i.second << "\n";
    }
    

}