#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n,m; cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0 ; j < m; j++){
            cin >> arr[i][j];
        }
    }
    vector<vector<int>> visited(n, vector<int>(m,0));
    vector<vector<int>> possible(n, vector<int>(m,0));
    unordered_map<char,pair<int,int>> directions;
    directions['L'] = {0,-1};
    directions['R'] = {0,1};
    directions['U'] = {-1,0};
    directions['D'] = {1,0};
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (visited[i][j]){
                continue;
            }
            if (arr[i][j] == '?'){
                continue;
            }
            stack<pair<int,int>> dfs;
            dfs.push({i,j});
            int finalcolor = -1; //1 is cant, 2 is can
            while (!dfs.empty()){
                if (visited[dfs.top().first][dfs.top().second] == 1){
                    visited[dfs.top().first][dfs.top().second] = 2;
                    possible[dfs.top().first][dfs.top().second]= finalcolor;
                    dfs.pop();
                } else{
                    visited[dfs.top().first][dfs.top().second] = 1;
                    pair<int,int> newcoords = {directions[arr[dfs.top().first][dfs.top().second]].first+dfs.top().first,directions[arr[dfs.top().first][dfs.top().second]].second+dfs.top().second};
                    if (newcoords.first < 0 || newcoords.first == n || newcoords.second < 0 || newcoords.second == m){
                        finalcolor = 2;
                    }
                    else if (visited[newcoords.first][newcoords.second] == 2){
                        finalcolor = possible[newcoords.first][newcoords.second];
                    } else if (visited[newcoords.first][newcoords.second] == 1){
                        finalcolor = 1;
                    } else if (arr[newcoords.first][newcoords.second] == '?'){
                        finalcolor = 1;
                    } else{
                        dfs.push(newcoords);
                    }
                }
            }
        }
    }
    for (int i =0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (visited[i][j] == 0){
                bool onlyescape = true;
                for (auto k : directions){
                    pair<int,int> newcoords =  {k.second.first+i,k.second.second+j};
                    if (newcoords.first < 0 || newcoords.first == n || newcoords.second < 0 || newcoords.second == m){
                        continue;
                    }
                    if (possible[newcoords.first][newcoords.second] != 2){
                        onlyescape = false;
                        break;
                    }
                }
                if (onlyescape){
                    possible[i][j] = 2;
                } else{
                    possible[i][j] = 1;
                }
            }
        }
    }
    int finalans = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            finalans += (possible[i][j]==1);
        }
    }
    cout << finalans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}