#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    vector<int> count(3,0);
    vector<set<int>> positions(3);
    for (int i= 0 ; i < n; i++){
        cin >> arr[i];
        count[arr[i]] += 1;
        positions[arr[i]].insert(i);
    }
    vector<pair<int,int>> operations;
    vector<int> optimal(n);
    for (int i = 0; i < count[0]; i++){
        optimal[i] = 0;
    }
    for (int i = count[0]; i < count[0] + count[1]; i++){
        optimal[i] = 1;
    }
    for (int i = count[0]+count[1]; i < n; i++){
        optimal[i] = 2;
    }
    for (int i = 0; i < count[0]; i++){
        if (arr[i] == 1){
            swap(arr[i], arr[*positions[0].rbegin()]);
            operations.push_back({i,*positions[0].rbegin()});
            positions[1].erase(i);
            positions[1].insert(*positions[0].rbegin());
            positions[0].erase(*positions[0].rbegin());
            positions[0].insert(i);
        }
    }
    for (int i = 0; i < n; i++){
        if (arr[i] == optimal[i]){
            continue;
        }
        if (optimal[i]==0){
            if (arr[i] == 1){
                swap(arr[i], arr[*positions[0].lower_bound(count[0])]);
                operations.push_back({i,*positions[0].lower_bound(count[0])});
                positions[1].erase(i);
                positions[1].insert(*positions[0].lower_bound(count[0]));
                positions[0].erase(*positions[0].lower_bound(count[0]));
                positions[0].insert(i);
            } else{
                //arr[i] = 2;
                int zeroindex = *positions[0].lower_bound(count[0]);
                int oneindex = *positions[1].rbegin();
                swap(arr[i], arr[oneindex]);
                swap(arr[i], arr[zeroindex]);
                operations.push_back({i,oneindex});
                operations.push_back({i,zeroindex});
                positions[0].erase(zeroindex);
                positions[0].insert(i);
                positions[1].erase(oneindex);
                positions[1].insert(zeroindex);
                positions[2].erase(i);
                positions[2].insert(oneindex);
            }
        } else if (optimal[i] == 1){
            //arr[i] = 2 is true
            swap(arr[i], arr[*positions[1].rbegin()]);
            operations.push_back({i,*positions[1].rbegin()});
            positions[2].erase(i);
            positions[2].insert(*positions[1].rbegin());
            positions[1].erase(*positions[1].rbegin());
            positions[1].insert(i);

        }
    }
    assert(operations.size() <= n);
    cout << operations.size() << "\n";
    for (auto i : operations){
        cout << i.first+1 << " " << i.second+1 << "\n";
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}