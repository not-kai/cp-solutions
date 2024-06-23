#include <bits/stdc++.h>
typedef long long i1;
using namespace std;
int main() {
    i1 n,k;
    vector<i1> arr;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    i1 totalans = 0;
    for (i1 i = 0 ; i < n; i++){
        i1 temp; cin >> temp; arr.push_back(temp);
        totalans += temp*temp;
    }
    multiset<i1> grr;
    for (i1 i = 0; i < n; i++){
        for (i1 j = 0; j < arr[i]-1; j++){
            i1 cost1 = (arr[i]/(j+1))*(arr[i]/(j+1))*(j+1-(arr[i]%(j+1))) + ((arr[i]/(j+1))+1)*((arr[i]/(j+1))+1)*(arr[i]%(j+1));
            i1 cost2 = (arr[i]/(j+2))*(arr[i]/(j+2))*(j+2-(arr[i]%(j+2))) + ((arr[i]/(j+2))+1)*((arr[i]/(j+2))+1)*(arr[i]%(j+2));
            grr.insert(cost1-cost2);
            if (grr.size() > k-n){
                grr.erase(grr.begin());
                if (grr.upper_bound(cost1-cost2) == grr.begin()){
                    break;
                }
            }
        }
    }
    for (i1 i : grr){
        totalans -= i;
    }
    cout << totalans << "\n";



}