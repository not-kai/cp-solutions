#include <bits/stdc++.h>
typedef long long i1;
using namespace std;
void solve() {
    i1 n,m; cin >> n >> m;
    vector<unordered_map<i1,i1>> graph(n);
    vector<i1> batteries(n);
    for (i1 i = 0; i  < n; i++){
        cin >> batteries[i];
    }
    i1 maxweight = 0;
    for (i1 i = 0; i < m; i++){
        i1 a,b,w; cin >> a >> b >> w;
        maxweight = max(maxweight,w);
        a -= 1;
        b -= 1;
        if (graph[a].find(b) == graph[a].end()){
            graph[a][b] = w;
        } else{
            graph[a][b] = min(graph[a][b],w);
        }
    }
    i1 ans = INT_MAX;
    i1 low = 1;
    i1 high = maxweight;
    while (low <= high){
        i1 mid = (low+high)/2;
        vector<i1> maxbattery(n,-1);
        maxbattery[0] = min(mid,batteries[0]);
        for (i1 i = 0; i < n-1; i++){
            for (auto j : graph[i]){
                if (j.second <= maxbattery[i]){
                    maxbattery[j.first] = min(mid,max(maxbattery[j.first],maxbattery[i]+batteries[j.first]));
                }
            }
        }
        if (maxbattery[n-1] != -1){
            ans = min(ans,mid);
            high = mid-1;
        } else{
            low = mid+1;
        }
    }
    if (ans != INT_MAX){
        cout << ans << "\n";
    } else{
        cout << -1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i1 t; cin >> t;
    for (i1 i = 0;i < t; i++){
        solve();
    }
}
