    #include <bits/stdc++.h>
    #include <ext/pb_ds/detail/standard_policies.hpp>
    #include <ext/pb_ds/assoc_container.hpp>
     
    using namespace std;
    using namespace __gnu_pbds;
    typedef long long i1;
    typedef tree<
            i1,
            null_type,
            less<i1>,
            rb_tree_tag,
            tree_order_statistics_node_update>
            ordered_set;
    void solve(i1 z) {
        i1 n; cin >> n;
        vector<i1> news(n);
        vector<i1> newt(n);
        vector<set<i1>> sletters(26);
        for (i1 i = 0; i < n; i++){
            char temp; cin >> temp;
            news[i] = temp - 'a';
     
            sletters[news[i]].insert(i);
        }
        for (i1 i = 0; i < n; i++){
            char temp; cin >> temp;
            newt[i] = temp - 'a';
        }
     
        i1 ans = LONG_LONG_MAX;
        i1 currans = 0;
        ordered_set removed;
        ordered_set added;
        i1 onindex = 0;
        for (i1 i = 0; i < n; i++){
            i1 minindextoless =LONG_LONG_MAX;
            while (removed.order_of_key(onindex+1) - removed.order_of_key(onindex) != 0){
                onindex += 1;
            }
            for (i1 j = newt[i]-1; j >= 0; j--){
                if (sletters[j].empty()){
                    continue;
                }
                minindextoless = min(minindextoless, *(sletters[j].upper_bound(onindex-1)));
            }
            if (minindextoless != LONG_LONG_MAX){
                i1 minswaps = minindextoless + (removed.size() - removed.order_of_key(minindextoless)) - i;
                ans = min(ans, currans+minswaps);
            }
            if (sletters[newt[i]].empty()){
                break;
            } else{
                minindextoless = *(sletters[newt[i]].begin());
                sletters[newt[i]].erase(minindextoless);
                currans += minindextoless + (removed.size() - removed.order_of_key(minindextoless)) - i;
                removed.insert(minindextoless);
            }
        }
        if (ans == LONG_LONG_MAX){
            cout << -1 << "\n";
            return;
        } else{
            cout << ans << "\n";
            return;
        }
     
    }
     
    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        i1 t; cin >> t; for (i1 i = 0; i < t; i++){
            solve(i);
        }
    }
