#include <bits/stdc++.h>
using namespace std;
vector<unordered_set<int>> graph;
vector<int> answer;
int startingbitmask = 0;
int startingnode = -1;
bool rah(int node, int bitmask){
    if (bitmask == startingbitmask && node == startingnode){
        answer.push_back(node);
        return true;
    }
    bool partofcycle = false;
    for (int i : graph[node]){
        if (i == startingnode && bitmask == startingbitmask){
            answer.push_back(node);
            return true;
        }
        if ((startingbitmask >> i & 1) && !(bitmask >> i & 1)){
            if (rah(i, bitmask + (1<<i))){
                partofcycle = true;
                break;
            }
        }
    }
    if (partofcycle){
        answer.push_back(node);
        return true;
    } else{
        return false;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; cin >> n >> m;
    graph.resize(n);
    for (int i = 0; i < m ;i++){
        int a, b; cin >> a >> b;
        a-=1;
        b-=1;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    bool pathexist[1 << n][n];
    memset(pathexist, 0, sizeof pathexist);
    for (int i = 0; i < n; i++){
        pathexist[1<<i][i] = true;
    }
    for (int bitmask = 0; bitmask < (1 << n); bitmask++){
        for (int i = 0; i < n; i++){
            if (pathexist[bitmask][i]){
                for (int next : graph[i]){
                    if (bitmask >> next & 1){
                        continue;
                    } else{
                        pathexist[bitmask + (1 << next)][next] = true;
                    }
                }
            }
        }
    }
    for (int bitmask = 1; bitmask < (1<<n); bitmask++){
        bool changed = false;
        bool cycle = true;
        unordered_set<int> cyclenodes;
        vector<int> trueanswer(n);
        for (int i = 0; i < n; i++){
            if ((bitmask >> i & 1)){
                cyclenodes.insert(i);
                if (pathexist[bitmask][i]){
                    changed = true;
                } else{
                    changed = true;
                    cycle = false;
                }
            }
        }
        bool valid = true;
        if (changed && cycle){
            for (int i = 0; i < n; i++){
                if (!(bitmask >> i & 1)){
                    bool found = false;
                    for (int j : cyclenodes){
                        if (graph[i].find(j) != graph[i].end()){
                            found = true;
                        }
                    }
                    if (!found){
                        valid = false;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++){
            if ((bitmask>>i & 1)){
                continue;
            }
            bool grr = false;
            for (int j : graph[i]){
                if (cyclenodes.find(j) != cyclenodes.end()){
                    trueanswer[i] = j;
                    grr = true;
                    break;
                }
            }
            if (!grr){
                valid = false;
                break;
            }
        }
        if (valid && changed && cycle && cyclenodes.size() > 1){
            startingnode = *cyclenodes.begin();
            startingbitmask = bitmask;
            answer.clear();
            rah(startingnode, (1<<startingnode));
            for (int i = 0; i < answer.size()-1; i++){
                trueanswer[answer[i]] = answer[i+1];
            }
            trueanswer[answer[answer.size()-1]] = answer[0];
            cout << "YES" << "\n";
            for (int i = 0; i < n; i++){
                cout << trueanswer[i] + 1 << " ";
            }
            return 0;
        }
    }
    cout << "NO" << "\n";
}