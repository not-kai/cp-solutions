#include <bits/stdc++.h>
using namespace std;
int n,m;
struct HASH{
    size_t operator()(const pair<int,int>&x)const{
        return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
    }
};
vector<vector<pair<pair<int,int>,int>>> graph;
vector<vector<pair<pair<int,int>,int>>> graph2;
vector<vector<pair<int,bool>>> distances;
//unordered_map<int, vector<pair<pair<int,int>,int>>> graph;
//unordered_map<int, vector<pair<pair<int,int>,int>>> graph2;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    graph.resize(n+1);
    graph2.resize(n+1);
    distances.resize(n+1, vector<pair<int,bool>>(51));
    for (int i = 1; i <= n; i++){
        distances[i][0] = {1e9,false};
    }
    for (int i = 0; i < m; i++){
        int a,b,w; cin >> a >> b >> w;
        graph2[a].push_back({{b,0},w});  //vertex, then distance
        graph2[b].push_back({{a,0},w});
        graph[a].push_back({{b,w},w});  //vertex, then distance
        graph[b].push_back({{a,w},w});
        distances[a][0] = {1e9,false};
        distances[a][w] = {1e9,false};
        distances[b][0] = {1e9,false};
        distances[b][w] = {1e9,false};
    }
    priority_queue<pair<int,pair<int,int>>> pq; //negative distance, vertex
    distances[1][0] = {0,false};
    pq.push({0,{1,0}});
    while (!pq.empty()){
        auto current = pq.top();
        pq.pop();
        int distance = current.first * -1;
        auto vertex = current.second;
        if (distances[vertex.first][vertex.second].second){
            continue;
        }
        distances[vertex.first][vertex.second].second = true;
        if (vertex.second == 0){ //first move
            for (auto i : graph[vertex.first]){
                if (distances[i.first.first][i.first.second].second){
                    continue;
                }
                if (distances[i.first.first][i.first.second].first > distance + (i.second * i.second)){
                    distances[i.first.first][i.first.second].first = distance + (i.second * i.second);
                    pq.push({-distances[i.first.first][i.first.second].first, i.first});
                }
            }
        } else{
            for (auto i : graph2[vertex.first]){
                if (distances[i.first.first][i.first.second].second){
                    continue;
                }
                if (distances[i.first.first][i.first.second].first > distance + (i.second * i.second) + 2 * vertex.second * i.second){
                    distances[i.first.first][i.first.second].first = distance + (i.second * i.second) + 2 * vertex.second * i.second;
                    pq.push({-distances[i.first.first][i.first.second].first, i.first});
                }
            }
        }
    }
    for (int i = 1; i <= n; i++){
        if (!distances[i][0].second){
            cout << -1 << " ";
        } else{
            cout << distances[i][0].first << " ";
        }
    }

    
}