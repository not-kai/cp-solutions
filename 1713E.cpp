#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n; cin >> n;
    int arr[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    unordered_map<int, vector<pair<pair<int,int>,pair<int,int>>>> graph;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            //prio = {i,j}
            if (arr[i][j] > arr[j][i]){ //{prio, type} type = {number, typeofedge}
                graph[i].push_back({{i,j},{j,-1}});
                graph[j].push_back({{i,j},{i,-1}});
            } else if (arr[i][j] < arr[j][i]){
                graph[i].push_back({{i,j},{j,1}});
                graph[j].push_back({{i,j},{i,1}});
            }
        }
    }
    unordered_set<int> notvisited;
    for (int i = 0; i < n; i++){
        notvisited.insert(i);
    }
    vector<pair<int,pair<int,int>>> rah(n); //{actual number, prio}
    for (int i = 0; i <n; i++){
        rah[i] = {0,{INT_MAX,INT_MAX}};
    }
    while (!notvisited.empty()){
        priority_queue<pair<pair<int,int>,int>> prio; //{prio, realnumber}, prio is negative
        prio.push({{0,0},*notvisited.begin()});
        rah[*notvisited.begin()] = {-1,{0,0}};
        //remember to erase
        while (!prio.empty()) {
            auto grr = prio.top();
            prio.pop();
            //cout << "currently on " << grr.second << "\n";
            for (auto i: graph[grr.second]) {
                //cout << "currently checking " << i.second.first << "\n";
                if (notvisited.find(i.second.first) == notvisited.end()) {
                    continue;
                }
                if (i.first < rah[i.second.first].second) {
                    //cout << "the edge between " << i.second.first << " and " << grr.second << " is " << i.second.second
                     //    << "\n";
                    //cout << grr.second << " is right now " << rah[grr.second].first << "\n";
                    rah[i.second.first].first = (i.second.second) * rah[grr.second].first;
                    //cout << "changing " << i.second.first << " to " << (i.second.second) * rah[grr.second].first
                    //     << "\n";
                    rah[i.second.first].second = i.first;
                    prio.push({{-i.first.first, -i.first.second}, i.second.first});
                }
            }
            notvisited.erase(grr.second);
        }
    }
    for (int i = 0; i < n; i++){
        if (rah[i].first == 1){
            for (int j = 0; j < n; j++){
                swap(arr[i][j], arr[j][i]);
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}