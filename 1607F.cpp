#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0; i < t; i++){
        int n,m; cin >> n >> m;
        char squares[n][m];
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> squares[i][j];
            }
        }
        unordered_map<int,int> answer;
        unordered_set<int> notvisited;
        for (int i = 0; i < n*m; i++){
            notvisited.insert(i);
        }
        int rah[n*m];
        memset(rah, 0, sizeof rah);
        //unordered_map<int, int> rah;
        while (!notvisited.empty()){
            int current = *notvisited.begin();
            notvisited.erase(current);
            vector<int> grr;
            grr.push_back(current);
            //rah.clear();
            rah[current] = 0;
            bool fallendown = false;
            bool cycle = false;
            while (true){
                if (squares[current/m][current%m] == 'R'){
                    if (current%m >= m-1){
                        fallendown = true;
                        break;
                    }
                    current+=1;
                } else if (squares[current/m][current%m] == 'L'){
                    if (current%m <= 0){
                        fallendown = true;
                        break;
                    }
                    current -= 1;
                } else if (squares[current/m][current%m] == 'U'){
                    if (current/m == 0){
                        fallendown = true;
                        break;
                    }
                    current -= m;
                } else if (squares[current/m][current%m] == 'D'){
                    if (current/m == n-1){
                        fallendown = true;
                        break;
                    }
                    current += m;
                }
                if (answer[current] != 0){
                    break;
                }
                if (rah[current] != 0 || grr[0] == current){
                    cycle = true;
                    break;
                }
                grr.push_back(current);
                rah[current] = (int) grr.size()-1;
                notvisited.erase(current);
            }
            if (fallendown){
                int temp = 1;
                for (int i = (int) grr.size()-1; i >= 0; i--){
                    answer[grr[i]] = temp;
                    temp += 1;
                    rah[grr[i]] = 0;
                }
            } else if (cycle){
                for (int i = rah[current]; i < (int) grr.size(); i++){
                    answer[grr[i]] = grr.size() - rah[current];
                }
                int temp = grr.size() - rah[current] +1;
                for (int i = rah[current]-1; i >= 0; i--){
                    answer[grr[i]] = temp;
                    temp += 1;
                }
                for (int i = 0; i < (int) grr.size(); i++){
                    rah[grr[i]] = 0;
                }
            } else{
                int temp = 1+answer[current];
                for (int i = (int) grr.size()-1; i >= 0; i--){
                    answer[grr[i]] = temp;
                    temp += 1;
                    rah[grr[i]] = 0;
                }
            }
        }

        int maxx, maxy, currmax(INT_MIN);
        for (int i = 0; i < n*m; i++){
            if (answer[i] > currmax){
                maxx = i/m;
                maxy=i%m;
                currmax=answer[i];
            }
        }
        cout << maxx+1 << " " << maxy+1 << " " << currmax << "\n";
    }
}
