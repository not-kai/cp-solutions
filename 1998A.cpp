#include <bits/stdc++.h>
using namespace std;
void solve() {
    int x,y,k; cin >> x >> y >> k;
    vector<pair<int,int>> points;
    if (k%2 == 1){
        points.push_back({x,y});
        k-= 1;
    }
    int dist = 1;
    while (k != 0){
        points.push_back({x-dist,y});
        points.push_back({x+dist,y});
        dist += 1;
        k -= 2;
    }
    for (auto i : points){
        cout << i.first << " " << i.second << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0; i < t; i++){solve();}
}