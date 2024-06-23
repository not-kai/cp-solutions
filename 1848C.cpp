#include <bits/stdc++.h>
using namespace std;
int mod(int n, int k){
    int answer = n%k;
    if (answer < 0){
        answer += k;
    }
    return answer;
}
void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    vector<int> arr2(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++){
        cin >> arr2[i];
    }
    unordered_set<int> rahh;
    for (int i = 0; i < n; i++){
        if (arr[i] == 0 && arr2[i] == 0){
            continue;
        } else if (arr[i] == 0){
            rahh.insert(1);
            continue;
        } else if (arr2[i] == 0){
            rahh.insert(2);
            continue;
        }
        while (mod(arr[i],2) == 0 && mod(arr2[i],2) == 0){
            arr[i]/=2;
            arr2[i]/=2;
        }
        if (mod(arr[i],2) == 0){
            if (mod(arr2[i], 4)== 1){
                rahh.insert(1);
            } else if (mod(arr2[i], 4) == 2){
                rahh.insert(0);
            } else if (mod(arr2[i], 4) == 3){
                rahh.insert(1);
            } else{
                rahh.insert(2);
            }
        } else{
            if (mod(arr2[i], 2)==0){
                rahh.insert(2);
            } else{
                rahh.insert(0);
            }
        }
    }
    if (rahh.size() > 1){
        cout << "NO" << "\n";
        return;
    }
    cout << "YES" << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 0; cin >> t; for (int i = 0; i < t; i++){solve();}
}
