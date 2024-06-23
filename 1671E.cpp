#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
void solve() {

}
int pleasework[(1<<18)+1];
int n;
int sizeoftree;
long long dp(int node){
    if (node*2 > sizeoftree){
        return 1;
    }
    if (pleasework[node*2] == pleasework[node*2+1]){
        return (dp(node*2)*dp(node*2+1))%MOD;
    } else{
        return (2*dp(node*2)*dp(node*2+1))%MOD;
    }

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    sizeoftree = (1 << n) - 1; //start with index 1
    memset(pleasework, 0, sizeof pleasework);
    vector<int> arr(sizeoftree+1);
    for (int i = 1; i<=sizeoftree; i++){
        char temp; cin >> temp;
        arr[i] = temp - 'A';
    }
    for (int i = (1 << (n-1)); i < (1<<n); i++){
        pleasework[i] = arr[i]+1;
    }
    for (int power = n-2; power >= 0; power--){
        map<pair<int,pair<int,int>>,vector<int>> mp;
        for (int i = (1 << (power)); i < (1 << (power+1)); i++){
            int first = min(pleasework[i*2], pleasework[i*2+1]);
            int second = max(pleasework[i*2], pleasework[i*2+1]);
            mp[{arr[i],{first, second}}].push_back(i);
        }
        int counter = 0;
        for (auto i : mp){
            counter += 1;
            for (int j : i.second){
                pleasework[j] = counter;
            }
        }
    }
    cout << dp(1) << "\n";

}