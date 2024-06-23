#include <bits/stdc++.h>
using namespace std;
int bitmaskdp[(1 << 17)];
bool alreadyforbidden[(1<<17)][17][17];
int seconddp[(1<<17)];
int combos[17][17];
int n,k;
string s;
int instances[17][100000];
void mask(int bitmask, int a, int b){
    if (alreadyforbidden[bitmask][a][b] || alreadyforbidden[bitmask][b][a]){
        return;
    }
    for (int i = 0; i < k; i++){
        if (i == a || i == b){
            continue;
        }
        if ((bitmask >> i) & 1){
            mask(bitmask - (1 << i), a, b);
        }
    }
    alreadyforbidden[bitmask][a][b] = true;
    bitmaskdp[bitmask] = -1;
}
int costforbitmask(int bitmask){
    int tempanswer = 0;
    for (int j = 0; j < k; j++){
        if ((bitmask>>j) & 1){
            tempanswer += instances[j][n-1];
        }
    }
    return tempanswer;
}
int returnmin(int bitmask){
    if (seconddp[bitmask] != 0){
        return seconddp[bitmask];
    }
    int currentanswer = costforbitmask(bitmask);
    for (int i = 0; i < k; i++){
        if ((bitmask >> i) & 1) {
            if (bitmaskdp[bitmask - (1 << i)] != -1) {
                currentanswer = min(currentanswer, returnmin(bitmask - (1 << i)));
            }
        }
    }
    seconddp[bitmask] = currentanswer;
    return currentanswer;
}
int main() {
    cin >> n >> k;
    vector<pair<int,int>> queries;
    vector<vector<int>> positions (k);
    for (int i = 0; i < n; i++){
        char c;
        cin >> c;
        s += c;
    }
    for (int i = 0; i < k; i++){
        for (int j = 0; j < k; j++){
            cin >> combos[i][j];
            if (combos[i][j] == 0){
                queries.push_back({i,j});
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < k; j++){
            if (i != 0) {
                instances[j][i] = instances[j][i - 1];
            }
        }
        instances[s.at(i)-'a'][i] += 1;
        positions[s.at(i)-'a'].push_back(i);
    }
    for (int i = 0; i < queries.size(); i++){
        if (positions[queries[i].second].empty() || positions[queries[i].first].empty()){
            continue;
        }
        if (queries[i].first != queries[i].second) {
            int q2 = 0;
            for (int j = 0; j < positions[queries[i].first].size(); j++) {
                while (q2 < positions[queries[i].second].size() &&
                       positions[queries[i].first][j] >= positions[queries[i].second][q2]) {
                    q2 += 1;
                }
                if (q2 == positions[queries[i].second].size()) {
                    break;
                }
                int startingmask = (1 << k) - 1;
                for (int l = 0; l < k; l++) {
                    if (l == queries[i].first){
                        continue;
                    }
                    if (instances[l][positions[queries[i].second][q2]-1]-instances[l][positions[queries[i].first][j]] > 0) {
                        startingmask -= (1 << l);
                    }
                }
                mask(startingmask, queries[i].first, queries[i].second);
            }
        } else{
            for (int j = 0; j < positions[queries[i].first].size()-1; j++){
                int startingmask = (1 << k) - 1;
                for (int l = 0; l < k; l++) {
                    if (l == queries[i].first){
                        continue;
                    }
                    if (instances[l][positions[queries[i].second][j+1]-1]-instances[l][positions[queries[i].first][j]] > 0) {
                        startingmask -= (1 << l);
                    }
                }
                mask(startingmask, queries[i].first, queries[i].second);
            }
        }
    }
    /*
    for (int i = 0; i < queries.size(); i++){
        unordered_set<int> notallowed;
        bool firstset = false;
        for (int j = 0; j < n; j++){
            if (firstset && s.at(j)-'a' == queries[i].second) {
                int startingmask = (1 << k) - 1;
                for (int l: notallowed) {
                    startingmask -= (1 << l);
                }
                mask(startingmask, queries[i].first, queries[i].second);
                firstset = false;
            }
            if (s.at(j)-'a' == queries[i].first){
                firstset = true;
                notallowed.clear();
            }
            else if (firstset){
                notallowed.insert(s.at(j)-'a');
            }
        }
    }
     */
    memset(seconddp, -1, sizeof seconddp);
    seconddp[0] = 0;
    for (int i = 0; i < (1<<k); i++){
        if (i != 0 && seconddp[i] == -1){
            if (bitmaskdp[i] != -1){
                seconddp[i] = costforbitmask(i);
            } else{
                continue;
            }
        }
        for (int j = 0; j < k; j++){
            if (!((i >> j) & 1)) {
                if (bitmaskdp[i + (1 << j)] != -1) {
                    if (seconddp[i+(1<<j)] == -1){
                        seconddp[i+(1<<j)] = seconddp[i];
                    } else {
                        seconddp[i + (1 << j)] = min(seconddp[i + (1 << j)], seconddp[i]);
                    }
                }
            }
        }
    }
    cout << seconddp[(1<<k)-1];
}