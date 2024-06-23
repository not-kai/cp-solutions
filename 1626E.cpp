#include <bits/stdc++.h>
using namespace std;
int black[300001];
int subtree[300001];
int n;
int accessible[300001];
unordered_map<int, vector<int>> tree;
vector<pair<int,int>> edges;
unordered_map<int, vector<int>> directedgraph;
int parents[300001];
void getparents(int node){
    for (int i : tree[node]){
        if (i == parents[node]){
            continue;
        }
        parents[i] = node;
        getparents(i);
    }
}
int getblack(int node){
    if (subtree[node] != -1){
        return subtree[node];
    }
    int answer = 0;
    if (black[node] == 1){
        answer += 1;
    }
    for (int i : tree[node]){
        if (i == parents[node]){
            continue;
        }
        answer += getblack(i);
    }
    subtree[node] = answer;
    return answer;
}
int main() {

    cin >> n;
    int totalblack = 0;
    for (int i = 1; i <= n; i++){
        cin >> black[i];
        if (black[i] == 1){
            totalblack += 1;
        }
    }

    for (int i = 0; i < n-1; i++){
        int a,b; cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
        if (a > b){
            swap(a,b);
        }
        edges.push_back({a,b});
    }
    memset(parents,-1,sizeof parents);
    memset(subtree, -1, sizeof subtree);
    getparents(1);
    getblack(1);

    for (auto i : edges){
        int x = i.first; int y = i.second;
        if (x == parents[y]){
            swap(x,y);
        }
        //y is always the parent
        //reversed the edges
        if (black[x]){
            directedgraph[x].push_back(y);
        } else if (getblack(x) >= 2){
            directedgraph[x].push_back(y);
        }

        if (black[y]){
            directedgraph[y].push_back(x);
        } else if (totalblack-getblack(x) >= 2){
            directedgraph[y].push_back(x);
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++){
        if (black[i]){
            q.push(i);
        }
    }
    while (!q.empty()){
        int rah = q.front(); q.pop();
        if (accessible[rah]){
            continue;
        }
        accessible[rah] = 1;
        for (int i : directedgraph[rah]){
            if (!accessible[i]) {
                q.push(i);
            }
        }
    }
    for (int i = 1; i <= n; i++){
        if (accessible[i]){
            cout << 1 << " ";
        } else{
            cout << 0 << " ";
        }
    }



}
