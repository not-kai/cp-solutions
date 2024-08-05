    #include <bits/stdc++.h>
     
    typedef long long i1;
    using namespace std;
     
    void solve() {
        i1 n,m; cin >> n >> m;
        vector<vector<i1>> graph(n);
        vector<i1> initial(n);
        vector<i1> target(n);
        for (i1 i = 0; i < n; i++){
            cin >> initial[i];
        }
        for (i1 i = 0; i < n; i++){
            cin >> target[i];
        }
        vector<i1> diff(n);
        for (i1 i = 0; i < n; i++){
            diff[i] = target[i] - initial[i];
        }
        for (i1 i = 0; i < m; i++){
            i1 a,b; cin >> a >> b;
            graph[a-1].push_back(b-1);
            graph[b-1].push_back(a-1);
        }
        vector<i1> colors(n);
        queue<i1> bfs;
        bfs.push(0);
        colors[0] = 1;
        bool isbipartite = true;
        while (!bfs.empty()){
            if (!isbipartite){
                break;
            }
            i1 node = bfs.front(); bfs.pop();
            for (i1 i : graph[node]){
                if (colors[i] == colors[node]){
                    isbipartite = false;
                    break;
                } else if (colors[i] == 0){
                    colors[i] = colors[node] * -1;
                    bfs.push(i);
                }
            }
        }
        if (isbipartite){
            i1 bigsum = 0;
            i1 smallsum = 0;
            for (i1 i = 0; i < n; i++){
                if (colors[i] == 1){
                    bigsum += diff[i];
                } else{
                    smallsum += diff[i];
                }
            }
            if (bigsum == smallsum){
                cout << "YES" << "\n";
            } else{
                cout << "NO" << "\n";
            }
        } else{
            i1 bigsum = 0;
            for (i1 i = 0 ; i < n; i++){
                bigsum += diff[i];
            }
            if (bigsum%2 == 0){
                cout << "YES" << "\n";
            } else{
                cout << "NO" << "\n";
            }
        }
     
    }
     
    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        i1 t; cin >> t; for (i1 i = 0; i < t; i++){
            solve();
        }
    }
