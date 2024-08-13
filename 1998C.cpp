#include <bits/stdc++.h>

typedef long long i1;
using namespace std;
void solve() {
    i1 n,k; cin >> n >> k;
    vector<i1> arr(n);
    vector<i1> b(n);
    for (i1 i =0 ; i < n; i++){
        cin >> arr[i];
    }
    for (i1 i =0 ; i < n; i++){
        cin >> b[i];
    }
    vector<i1> fixed;
    vector<i1> change;
    for (i1 i = 0; i < n; i++) {
        if (b[i] == 0) {
            fixed.push_back(arr[i]);
        } else {
            change.push_back(arr[i]);
        }
    }
    sort(fixed.begin(), fixed.end());
    sort(change.begin(), change.end());
    i1 ans = 0;
    if (!change.empty()) {
        vector<i1> temp;
        for (i1 i = 0; i < fixed.size(); i++) {
            temp.push_back(fixed[i]);
        }
        for (i1 i = 0; i < change.size() - 1; i++) {
            temp.push_back(change[i]);
        }
        sort(temp.begin(), temp.end());
        ans = change[change.size() - 1] + k + temp[(n - 2) / 2];
    }
    if (fixed.empty()){
        cout << ans << "\n";
        return;
    }
    vector<i1> temp2;
    i1 what = fixed.size()-1;
    for (i1 i = 0; i < what; i++){

        temp2.push_back(fixed[i]);
    } for (i1 i = 0; i < change.size(); i++){
        temp2.push_back(change[i]);
    }
    sort(temp2.begin(), temp2.end());
    i1 left = 0; i1 right = 2e9;
    i1 maxmedian = -1;
    while (left <= right){
        multiset<i1> changes;
        for (i1 i : change){
            changes.insert(i);
        }
        i1 mid = (left+right)/2;
        i1 upperindex = lower_bound(temp2.begin(), temp2.end(),mid) - temp2.begin();
        i1 lowerindex = (lower_bound(temp2.begin(), temp2.end(), mid) - temp2.begin())-1;
        i1 above = n-1 - upperindex;
        i1 below = lowerindex+1;
        if (above > below){
            maxmedian = max(maxmedian, mid);
            left = mid+1;
            continue;
        }
        i1 moveabove = 1+((below-above)/2);
        i1 tempk = k;
        while (tempk >= 0 && moveabove > 0){
            if (changes.lower_bound(mid) == changes.begin()){
                break;
            }
            i1 wanttomoveabove = *prev(changes.lower_bound(mid));
            if (tempk >= mid-wanttomoveabove){
                tempk -= mid-wanttomoveabove;
                moveabove -= 1;
                auto itr = changes.find(wanttomoveabove);
                if(itr!=changes.end()){
                    changes.erase(itr);
                }
            } else{
                break;
            }
        }
        if (moveabove <= 0){
            maxmedian = max(maxmedian, mid);
            left = mid+1;
        } else{
            right = mid-1;
        }
    }
    ans = max(ans, fixed[what]+maxmedian);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i1 t; cin >> t; for (i1 i = 0; i < t ;i ++){solve();}
}