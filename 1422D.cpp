#include <bits/stdc++.h>

typedef int i1;
using namespace std;

void solve() {

}
struct HASH{
    size_t operator()(const pair<i1,i1>&x)const{
        return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i1 n,m; cin >> n >> m;
    pair<i1,i1> starting, ending; cin >> starting.first >> starting.second >> ending.first >> ending.second;
    vector<pair<i1,i1>> points(m);
    for (i1 i = 0; i < m; i++){
        cin >> points[i].first >> points[i].second;
    }
    sort(points.begin(), points.end());
    unordered_map<pair<i1,i1>, vector<pair<i1,pair<i1,i1>>>,HASH> graph;
    for (i1 i = 0; i < m-1; i++){
        graph[points[i]].push_back({points[i+1].first - points[i].first, points[i+1]});
        graph[points[i+1]].push_back({points[i+1].first - points[i].first, points[i]});
    }
    std::sort(points.begin(), points.end(), [](auto &left, auto &right) {
        return left.second < right.second;
    });
    for (i1 i = 0; i < m-1; i++){
        graph[points[i]].push_back({points[i+1].second - points[i].second, points[i+1]});
        graph[points[i+1]].push_back({points[i+1].second - points[i].second, points[i]});
    }
    for (i1 i = 0; i < m; i++){
        graph[starting].push_back({min(abs(points[i].first - starting.first), abs(points[i].second - starting.second)), points[i]});
        graph[points[i]].push_back({abs(points[i].first - starting.first) + abs(points[i].second - starting.second), starting});
        graph[ending].push_back({min(abs(points[i].first - ending.first), abs(points[i].second - ending.second)), points[i]});
        graph[points[i]].push_back({abs(points[i].first - ending.first)+ abs(points[i].second - ending.second), ending});
    }
    graph[starting].push_back({abs(starting.first - ending.first) + abs(starting.second - ending.second), ending});
    graph[ending].push_back({abs(starting.first - ending.first) + abs(starting.second - ending.second), starting});
    unordered_map<pair<i1,i1>,i1,HASH> distances;
    unordered_map<pair<i1,i1>,bool,HASH> processed;
    for (auto i : points){
        distances[i] = INT_MAX;
        processed[i] = false;
    }
    distances[starting] = INT_MAX;
    distances[ending] = INT_MAX;
    processed[starting] = false;
    processed[ending] = false;
    priority_queue<pair<i1, pair<i1,i1>>> pq;
    pq.push({0, starting});
    while (!pq.empty()){

        auto node = pq.top().second;
        i1 weight = pq.top().first * -1;
        pq.pop();
        if (processed[node]){
            continue;
        }
        processed[node] = true;
        for (auto i : graph[node]){
            if (weight + i.first < distances[i.second]){
                distances[i.second] = weight + i.first;
                pq.push({-distances[i.second],i.second});
            }
        }
    }
    cout << distances[ending] << "\n";
}
