#include <bits/stdc++.h>
#define NO cout << "NO" << "\n"; return;
using namespace std;
void solve(){
    int n,m;
    cin >> n >> m;
    unordered_map<int, unordered_set<int>> degree;
    for (int i = 0; i < m; i++){
        int a,b; cin >> a >> b;
        degree[a].insert(b);
        degree[b].insert(a);
    }
    int k = 0;
    for (int i = 0; i < 2e5; i++){
        if (i*(i+1) == m){
            k = i; break;
        }
    }
    if (k == 0){
        NO
    }
    int smaller = 0;
    int bigger = 0;
    unordered_set<int> nodeswithdegree4;
    for (int i = 1; i <= n; i++){
        if (degree[i].size() == 2){
            smaller += 1;
        } else if (degree[i].size() == 4){
            bigger += 1;
            nodeswithdegree4.insert(i);
        } else{
            NO
        }
    }
    if ((bigger != k || smaller != (k*(k-1)))){
        NO
    }
    int bordernodes = 0;
    for (int i = 1; i <= n; i++){
        if (nodeswithdegree4.find(i) != nodeswithdegree4.end()){
            int two = 0;
            int four = 0;
            for (int j : degree[i]){
                if (degree[j].size() == 2){
                    two += 1;
                } else{
                    four += 1;
                }
            }
            if (two != 2 || four != 2){
                NO
            }
        } else{
            int two = 0;
            int four = 0;
            for (int j : degree[i]){
                if (degree[j].size() == 2){
                    two += 1;
                } else{
                    four += 1;
                }
            }
            if (four == 2){
                NO
            } else if (four == 1){
                bordernodes += 1;
            }
        }
    }
    if (bordernodes != 2*k){
        NO
    }
    int startingnode = *nodeswithdegree4.begin();
    int currentnode = 0;
    int lastnode = startingnode;
    for (int i : degree[startingnode]){
        if (degree[i].size() == 4){
            currentnode = i;
            break;
        }
    }
    int traveledk = 1;
    while (true){
        for (int i : degree[currentnode]){
            if (i == lastnode){
                continue;
            }
            if (degree[i].size() == 4){
                lastnode = currentnode;
                currentnode = i;
                traveledk += 1;
                break;
            }
        }
        if (lastnode == currentnode){
            break;
        }
        if (startingnode == currentnode){
            break;
        }
    }
    if (traveledk != k){
        NO
    }
    for (int i : nodeswithdegree4){
        currentnode = 0;
        lastnode = i;
        for (int j : degree[i]){
            if (degree[j].size() == 2){
                currentnode = j;
                break;
            }
        }
        traveledk = 1;
        while (true){
            for (int j : degree[currentnode]){
                if (j == lastnode){
                    continue;
                }
                if (nodeswithdegree4.find(j) != nodeswithdegree4.end()) {
                    if (traveledk == k-1){
                        lastnode = currentnode;
                        currentnode = j;
                        traveledk += 1;
                        break;
                    } else{
                        NO
                    }
                } else{
                    lastnode = currentnode;
                    currentnode = j;
                    traveledk += 1;
                    break;
                }
            }
            if (currentnode == lastnode){
                break;
            }
            if (i == currentnode){
                break;
            }
        }
        if (traveledk != k){
            NO
        }
    }
    cout << "YES" << "\n";


}
int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    int t; cin >> t; for (int i = 0; i < t; i++){solve();}
}
