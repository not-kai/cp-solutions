#include <bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
typedef long long i1;

i1 gcd(i1 a, i1 b) { return b == 0 ? a : gcd(b, a % b); } //O(log(ab)) from euler probably
i1 lcm(i1 a, i1 b) { return a*b/gcd(a,b); } //O(log(ab))
typedef __gnu_pbds::tree<
        i1,
        __gnu_pbds::null_type,
        less<i1>,
        __gnu_pbds::rb_tree_tag,
        __gnu_pbds::tree_order_statistics_node_update>
        ordered_set;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i1 n,m,k;
    cin >> n >> m >> k;
    vector<i1> arr(n);
    vector<i1> arr2(m);
    unordered_map<i1,i1> grr;
    unordered_map<i1,i1> grr2;
    for (i1 i = 0; i < n; i++){
        cin >> arr[i];
        grr[arr[i]] = i;
    }
    for (i1 i = 0; i < m; i++){
        cin >> arr2[i];
        grr2[arr2[i]] = i;
    }
    if (n > m){
        swap(n,m);
        swap(arr, arr2);
        swap(grr, grr2);
    }
    ordered_set operations;
    i1 idkman[500001];
    for (i1 i = 0; i <= 500000; i++){
        idkman[i] = -1;
    }
    i1 diff = n-m;
    i1 curron = 0;
    for (i1 i = 0; i < m/gcd(n,m); i++){
        idkman[curron] = i;
        curron += diff;
        curron = ((curron%m)+m)%m;
    }
    for (i1 i = 0; i < arr.size(); i++){
        if (grr2.find(arr[i]) != grr2.end()){
            i1 posdiff = (((grr2[arr[i]] - i)%m)+m)%m;
            if (idkman[posdiff] == -1){
                continue;
            }
            operations.insert(i+1 + n*(idkman[posdiff]));
        }
    }
    i1 daysforcycle = lcm(n,m);
    i1 wrongperday = daysforcycle;
    for (i1 i : arr){
        if (grr2.find(i) != grr2.end() && ((((grr2[i] - grr[i])%m)+m)%m)%(gcd(n,m)) == 0){
            wrongperday -= 1;
        }
    }
    i1 ans = 0;
    if (k%wrongperday != 0){
        ans = (k/wrongperday)*daysforcycle;
        k %= wrongperday;
    } else{
        ans = ((k/wrongperday)-1)*daysforcycle;
        k = wrongperday;
    }
    for (auto i = operations.begin(); i != operations.end(); i++){
        i1 test = *i;
        if (test - (operations.order_of_key(test)+1) >= k){
            ans += k;
            ans += operations.order_of_key(test);
            cout << ans << "\n";
            return 0;
        }
    }
    ans += k;
    ans += operations.size();
    cout << ans << "\n";
    return 0;




}