#include <bits/stdc++.h>

typedef long long i1;
using namespace std;
unordered_map<i1,vector<i1>> graph;
unordered_map<i1,bool> vertices;
vector<i1> toposort;
void grrsort(i1 node){
    vertices[node] = true;
    for (i1 i : graph[node]){
        if (!vertices[i]){
            grrsort(i);
        }
    }
    toposort.push_back(node);
}
void solve(int time) {
    long long n,m; cin >> n >> m;
    vector<vector<i1>> sequences(n);
    for (i1 i = 0; i < n; i++){
        i1 length; cin >> length;
        for (i1 j = 0; j < length; j++){
            i1 temp; cin >> temp;
            sequences[i].push_back(temp);
        }
        sort(sequences[i].begin(), sequences[i].end());
    }
    /*
    if (time == 59){
        cout << n << "-" << m << "-";
        for (auto i : sequences){
            cout << i.size() << "-";
            for (long long j : i){
                cout << j << "-";
            }
            cout << "-";
        }
        return;
    }
     */
    long long maxmex = 0;
    vector<pair<i1,i1>> mexes(n);
    for (i1 i = 0; i < n; i++){
        i1 mex1 = 0;
        i1 mex2 = 1;
        for (i1 j = 0; j < sequences[i].size(); j++){
            if (sequences[i][j] == mex1){
                mex1 += 1;
                if (mex1 == mex2){
                    mex2 += 1;
                }
            } else if (sequences[i][j] == mex2){
                mex2 += 1;
            }
        }
        mexes[i] = {mex1,mex2};
        maxmex = max(mex1,maxmex);
        maxmex = max(mex2,maxmex);
    }
    unordered_map<i1,vector<i1>> grr;
    for (auto i : mexes){
        grr[i.first].push_back(i.second);
    }
    graph.clear();
    for (auto i : grr){ //same number is start, negative number is enter
        if (grr[i.first].size() == 1){
            graph[i.first].push_back(i.second[0]);
        } else{
            graph[i.first].push_back(i.first - 2000000000);
            for (i1 j : i.second){
                graph[i.first-2000000000].push_back(j);
            }
        }
    }
    vertices.clear();
    for (auto i : graph){
        vertices[i.first] = false;
        for (i1 j : i.second){
            vertices[j] = false;
            if (graph[j].empty()){
                continue;
            }
        }
    }
    toposort.clear();
    for (auto i : graph){
        if (!vertices[i.first]){
            grrsort(i.first);
        }
    }
    unordered_map<i1,i1> dp;
    long long maxofallnegative = -1;
    for (i1 i : toposort){
        if (i < 0){
            dp[i] = i + 2000000000;
        } else{
            dp[i] = i;
        }
        for (i1 j : graph[i]){
            dp[i] = max(dp[i], dp[j]);
            dp[i] = max(dp[i], j);
        }
        if (i < 0){
            maxofallnegative = max(maxofallnegative, dp[i]);
        }
        if (i >= 0 && !graph[i].empty()){
            maxofallnegative = max(maxofallnegative, i);
        }
    }
    long long answer = 0;
    for (i1 i = 0; i <= min(m,maxmex); i++){
        long long temp = maxofallnegative;
        temp = max(temp, i);
        temp = max(temp, dp[i]);
        answer += temp;
    }
    if (m > maxmex){
        answer += m*(m+1)/2;
        answer -= maxmex*(maxmex+1)/2;
    }
    cout << answer << "\n";



}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i1 t; cin >> t; for (i1 i = 0; i < t; i++){
        solve(i);
    }
}
