#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,k;
    cin >> n >> k;
    int graph[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> graph[i][j];
        }
    }
    srand(time(NULL));
    int minpath = INT_MAX;
    for (int randomiterations = 0; (randomiterations < 512*20); randomiterations++){
        bool colors[n];
        for (int i = 0; i < n; i++){
            colors[i] = rand()%2;
        }
        int dp[n][k+1];
        bool visited[n][k+1];
        for (int i = 0; i < n; i++){
            for (int j = 0; j <= k; j++){
                dp[i][j] = -1;
                visited[i][j] = false;
            }
        }
        visited[0][0] = true;
        for (int i = 0; i < n; i++){
            dp[i][0] = 0;
        }
        for (int length = 1; length <= k; length++){
            for (int node = 0; node < n; node++){
                for (int i = 0; i < n; i++){
                    if (i == node){
                        continue;
                    }
                    if (colors[i] != colors[node] && visited[i][length-1]){
                        if (visited[node][length] == false){
                            dp[node][length] = dp[i][length-1] + graph[i][node];
                            visited[node][length] = true;
                        } else {
                            dp[node][length] = min(dp[node][length], dp[i][length - 1] + graph[i][node]);
                        }
                    }
                }
            }
        }
        if (visited[0][k]) {
            minpath = min(minpath, dp[0][k]);
        }
    }
    cout << minpath << "\n";
}
