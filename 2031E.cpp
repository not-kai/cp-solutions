    #include <bits/stdc++.h>
    using namespace std;
    vector<int> tree;
    vector<vector<int>> tree2;
    int grr(int node){
        if (tree2[node].empty()){
            return 0;
        }
        priority_queue<int> temp;
        for (int i : tree2[node]){
            temp.push(-grr(i));
        }
        while (temp.size() > 2){
            int a = -temp.top(); temp.pop(); int b = -temp.top(); temp.pop();
            temp.push(-max(a,b)-1);
        }
        int maxheight = 0;
        while (!temp.empty()){
            int a = -temp.top(); temp.pop(); maxheight = max(a,maxheight);
        }
        return maxheight+1;
    }
    void solve() {
        int n; cin >> n;
        tree.clear();
        tree2.clear();
        tree.resize(n);
        tree2.resize(n);
        for (int i = 1; i < n; i++){
            cin >> tree[i];
            tree[i] -= 1;
            tree2[tree[i]].push_back(i);
        }
        cout << grr(0) << "\n";
     
    }
     
    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int t; cin >> t; for (int i = 0; i < t; i++){
                solve();
        }
    }
