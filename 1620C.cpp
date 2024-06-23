#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    for (int grr = 0; grr < t; grr++){
        int n,k; long long x; cin >> n >> k >> x;
        x -= 1;
        vector<char> rahh(n);
        for (int i = 0; i < n; i++){
            cin >> rahh[i];
        }
        vector<pair<int,int>> ast;
        int currenta = 0;
        int currast = 0;
        for (int i = 0; i < n; i++){
            if (rahh[i] == 'a'){
                if (currast != 0){
                    ast.push_back({currenta, currast});
                    currenta = 1;
                    currast = 0;
                } else{
                    currenta += 1;
                }
            } else{
                currast += 1;
            }
        }
        if (currast != 0){
            ast.push_back({currenta, currast});
            currenta = 0;
        }
        if (ast.empty()){
            for (int i = 0; i < n; i++){
                cout << rahh[i];
            }
            cout << "\n";
            continue;
        }
        vector<long long> prefixproducts((int) ast.size());
        prefixproducts[(int) ast.size()-1] = (ast[(int) ast.size()-1].second)*k+1;
        for (int i = (int) ast.size()-2; i >= 0; i--){
            if (prefixproducts[i+1] > x/(ast[i].second*k+1)+1){
                prefixproducts[i] = LONG_LONG_MAX;
            } else {
                prefixproducts[i] = prefixproducts[i + 1] * ((ast[i].second) * k + 1);
            }
        }
        prefixproducts.push_back(1);
        long long target = x;
        string answer = "";
        for (int i = 0; i < (int) ast.size(); i++){
            for (int j = 0; j < ast[i].first; j++){
                answer += "a";
            }
            if (target >= prefixproducts[i+1]){
                int number = target/prefixproducts[i+1];
                for (int j = 0; j < number; j++){
                    answer += "b";
                }
                target -= (number)*prefixproducts[i+1];
            }
        }
        for (int i = 0; i < currenta; i++){
            answer += "a";
        }
        cout << answer << "\n";
    }
}