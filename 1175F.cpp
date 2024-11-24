    #include <bits/stdc++.h>
    using namespace std;
    int n;
    int arr[300000];
    int perm(int left, int right){
        unordered_map<int,int> instances;
        for (int i = left; i <= right; i++){
            instances[arr[i]] = i;
        }
        int answer = 0;
        int connectedcomponents = 0;
        unordered_set<int> included;
        for (int i = 0; i < n; i++){
            if (instances.find(i) == instances.end()){
                return answer;
            }
            if (included.find(instances[i]-1) != included.end() && included.find(instances[i]+1) != included.end()){
                connectedcomponents -= 1;
            }
            else if (included.find(instances[i]-1) == included.end() && included.find(instances[i]+1) == included.end()){
                connectedcomponents += 1;
            }
            included.insert(instances[i]);
            if (connectedcomponents == 1){
                answer += 1;
            }
        }
        return answer;
    }
    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cin >> n;
        vector<vector<int>> ranges(n);
        for (int i = 0; i < n; i++){
            cin >> arr[i];
            arr[i] -= 1;
            ranges[arr[i]].push_back(i);
        }
        //permutation starts at 0
        vector<int> bad(n,-1);
        vector<int> bad2(n, -1);
        for (auto i : ranges){
            int whatthe = i.size()-1;
            for (int j = 0; j < whatthe; j++){
     
                bad[i[j]] = i[j+1];
                bad2[i[j+1]] = i[j];
            }
        }
        vector<pair<int,int>> searchranges;
        vector<pair<int,int>> overlap;
        int left = 0;
        int right = 0;
        while (right != n){
            if (bad2[right] != -1 && bad2[right] >= left){
                searchranges.push_back({left, right-1});
                overlap.push_back({bad2[right]+1, right-1});
                left = bad2[right]+1;
                right = left;
            }
            right += 1;
        }
        searchranges.push_back({left, right-1});
        int finalans = 0;
        for (auto i : searchranges){
            finalans += perm(i.first, i.second);
        }
        for (auto i : overlap){
            finalans -= perm(i.first, i.second);
        }
        cout << finalans << "\n";
     
     
     
    }
