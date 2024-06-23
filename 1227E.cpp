//solution notes:
//first bfs to find the min distance to the edge for every space
//store all the possible distances in a set (on second thought it's just 1 - max but whatever lol i wasn't thinking straight)
//binary search on possible T (max distance <= 1e6/2)
//for each binary search, label the nodes with distance greater than or equal to the distance with just the distance
//bfs outwards, updating each node with the maximum count
//afterwards, check if every node was marked, and if so, update the potential answer
//time & memory complexity = O(nlog(n))??? you binary search, and the bfs SHOULD be O(n) but i'm not entirely sure about that
//could very easily tle due to high constant factor

//other ideas in case this fails:
//if there is space with 3 open spaces next to it T=0
//i have no more fucking ideas lol

//also i assume O(n) -> n is actually n*m which is <= 1e6


#include <bits/stdc++.h>
using namespace std;
int n,m;
bool exists(int x, int y){
    return ((x >= 0 && x < n) && (y >= 0 && y < m));
}
int main() {
    vector<pair<int,int>> adjacent = {{0,1},{0,-1},{1,-1},{1,1},{1,0},{-1,1},{-1,-1},{-1,0}};
    cin >> n >> m;
    int arr[n][m];
    memset(arr, 0, sizeof arr);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            char x; cin >> x;
            if (x=='X'){
                arr[i][j] = 1;
            }
        }
    }

    //O(n)
    int distances[n][m];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (arr[i][j] > 0) {
                distances[i][j] = 9999999;
            } else{
                distances[i][j] = -1;
            }
        }
    }
    queue<pair<int,int>> bfs; //get all spaces next to an empty square in the bfs first
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (arr[i][j] == 0){
                continue;
            }
            int emptysquare = 0;
            for (auto k : adjacent){
                if ((i+k.first >= 0 && i+k.first < n) && (j+k.second >= 0 && j+k.second < m)){
                    if (arr[i+k.first][j+k.second] == 0){
                        emptysquare += 1;
                    }
                } else{
                    emptysquare += 1;
                }
            }
            //if next to an empty square or something idk
            if (emptysquare >= 1){
                bfs.push({i,j});
                distances[i][j] = 1;
            }
        }
    }


    int maxdistance = 0;

    //O(n)
    while (!bfs.empty()){
        auto onspace = bfs.front(); bfs.pop();
        for (auto k : adjacent){
            if (exists(onspace.first+k.first, onspace.second+k.second)){
                if (distances[onspace.first][onspace.second]+1 < distances[onspace.first+k.first][onspace.second+k.second]){
                    distances[onspace.first+k.first][onspace.second+k.second] = distances[onspace.first][onspace.second]+1;
                    bfs.push({onspace.first+k.first, onspace.second+k.second});
                    maxdistance = max(maxdistance, distances[onspace.first+k.first][onspace.second+k.second]);
                }
            }
        }
    }
    /*
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << distances[i][j] << " ";
        }
        cout << "\n";
    }
     */

    int potentialanswer = 1;
    int left = 1;
    int right = maxdistance;
    while (left <= right){
        int tempT = (left+right)/2;
        int hypothetical[n][m];
        memset(hypothetical, 0, sizeof hypothetical);
        queue<pair<int,int>> q;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (distances[i][j] >= tempT){
                    q.push({i,j});
                    hypothetical[i][j] = tempT;
                }
            }
        }

        while (!q.empty()){
            auto onspace = q.front(); q.pop();
            if (hypothetical[onspace.first][onspace.second] == 1){
                continue;
            }
            for (auto k : adjacent){
                if (exists(onspace.first+k.first, onspace.second+k.second)){
                    if (hypothetical[onspace.first][onspace.second]-1 > hypothetical[onspace.first+k.first][onspace.second+k.second]){
                        q.push({onspace.first+k.first, onspace.second+k.second});
                        hypothetical[onspace.first+k.first][onspace.second+k.second] = hypothetical[onspace.first][onspace.second]-1;
                    }
                }
            }
        }

        //checking if all nodes were reached
        bool flag = true;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (arr[i][j] > 0 && hypothetical[i][j] == 0){
                    flag = false;
                }
            }
        }

        if (flag){
            potentialanswer = max(potentialanswer, tempT);
            left = (left+right+2)/2;
        } else{
            right = (left+right-2)/2;
        }
    }
    cout << potentialanswer-1 << "\n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (distances[i][j] >= potentialanswer){
                cout << "X";
            } else{
                cout << ".";
            }
        }
        cout << "\n";
    }









}
