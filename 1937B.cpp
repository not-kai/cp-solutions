#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    int arr[n][2];
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < n; j++){
            char temp; cin >> temp;
            arr[j][i] = temp-'0';
        }
    }
    pair<int,int> up({0,0}), down({0,0});
    int numberofpaths = 1;
    vector<int> path;
    pair<int,int> final = {n-1, 1};
    int potentialpaths = 0;
    while (up != final && down != final){
        if (up == down){
            if (arr[up.first+1][0] < arr[down.first][down.second+1]){
                up.first += 1;
                down = up;
                path.push_back(arr[up.first][up.second]);
            } else if (arr[up.first+1][0] > arr[down.first][down.second+1]){
                up.second += 1;
                numberofpaths += potentialpaths;
                break;
            } else{
                up.first += 1;
                down.second += 1;
                path.push_back(arr[up.first][up.second]);
                potentialpaths += 1;
            }
        } else{
            if (up.first == n-1){
                numberofpaths += potentialpaths;
                break;
            }
            if (arr[up.first+1][0] < arr[down.first+1][down.second]){
                up.first += 1;
                down = up;
                potentialpaths = 0;
                path.push_back(arr[up.first][up.second]);
            } else if (arr[up.first+1][0] > arr[down.first+1][down.second]){
                numberofpaths += potentialpaths;
                up.second += 1;
                break;
            } else{
                potentialpaths += 1;
                up.first += 1;
                down.first += 1;
                path.push_back(arr[up.first][up.second]);
            }
        }
    }
    while (up.first != n-1){
        path.push_back(arr[up.first][up.second]);
        up.first += 1;
    }
    cout << arr[0][0];
    for (int i = 0; i < path.size(); i++){
        cout << (path[i]);
    }
    cout << arr[n-1][1] << "\n";
    cout << numberofpaths << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}