#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n,m;
    cin >> n;
    vector<int> matt;
    vector<int> mdef;
    vector<int> batt;
    vector<int> bdef;
    for (int i = 0; i < n; i++){
        int temp; cin >> temp; matt.push_back(temp);
    }
    for (int i = 0; i < n; i++){
        int temp; cin >> temp; mdef.push_back(temp);
    }
    cin >> m;
    for (int i = 0; i < m; i++){
        int temp; cin >> temp; batt.push_back(temp);
    }
    for (int i = 0; i < m; i++){
        int temp; cin >> temp; bdef.push_back(temp);
    }
    vector<pair<int,int>> mono;
    vector<pair<int,int>> bi;
    for (int i = 0; i < n; i++){
        mono.push_back({mdef[i], matt[i]});
    }
    for (int i = 0; i < m; i++){
        bi.push_back({bdef[i], batt[i]});
    }
    sort(mono.begin(), mono.end());
    sort(bi.begin(), bi.end());

    int mMaxAtt = 0;
    int bMaxAtt = 0;
    for (int i = 0; i < n; i++){
        mMaxAtt = max(mMaxAtt, mono[i].second);
    }
    for (int i = 0; i < m; i++){
        bMaxAtt = max(bMaxAtt, bi[i].second);
    }
    vector<int> mprefix(n);
    vector<int> bprefix(m);
    mprefix[0] = mono[0].second;
    bprefix[0] = bi[0].second;
    for (int i = 1; i < n; i++){
        mprefix[i] = max(mono[i].second, mprefix[i-1]);
    }
    for (int i = 1; i < m; i++){
        bprefix[i] = max(bi[i].second, bprefix[i-1]);
    }
    vector<int> msuffix(n);
    vector<int> bsuffix(m);
    msuffix[n-1] = mono[n-1].second;
    bsuffix[m-1] = bi[m-1].second;
    for (int i = n-2; i >= 0; i--){
        msuffix[i] = max(msuffix[i+1], mono[i].second);
    }
    for (int i = m-2; i >= 0; i--){
        bsuffix[i] = max(bsuffix[i+1], bi[i].second);
    }
    msuffix.push_back(0);
    bsuffix.push_back(0);
    //i think you can do binary search on this by {att value, int max} upperbound
    auto monowin = upper_bound(mono.begin(), mono.end(), make_pair(bMaxAtt-1, INT_MAX));
    auto biwin = upper_bound(bi.begin(), bi.end(), make_pair(mMaxAtt-1, INT_MAX));
    auto monoloss = mono.begin();
    auto biloss = bi.begin();

    while (true){
        bool update = false;
        int MmaxWatt = msuffix[monowin - mono.begin()];
        auto newbiloss = upper_bound(bi.begin(), bi.end(), make_pair(MmaxWatt-1, INT_MAX));
        if (newbiloss != biloss){
            update = true;
            biloss = newbiloss;
        }
        int BmaxWatt = bsuffix[biwin - bi.begin()];
        auto newmonoloss = upper_bound(mono.begin(), mono.end(), make_pair(BmaxWatt-1, INT_MAX));
        if (newmonoloss != monoloss){
            update = true;
            monoloss = newmonoloss;
        }
        if (monoloss != mono.begin() && mprefix[monoloss - mono.begin()-1] > msuffix[monoloss - mono.begin()]){
            auto newbiwin = upper_bound(bi.begin(), bi.end(), make_pair(msuffix[monoloss-mono.begin()]-1, INT_MAX));
            if (biwin != newbiwin){
                update = true;
                biwin = newbiwin;
            }
        }
        if (biloss != bi.begin() && bprefix[biloss - bi.begin()-1] > bsuffix[biloss - bi.begin()]){
            auto newmonowin = upper_bound(mono.begin(), mono.end(), make_pair(bsuffix[biloss-bi.begin()]-1, INT_MAX));
            if (monowin != newmonowin){
                update = true;
                monowin = newmonowin;
            }
        }
        if (!update){
            break;
        }
    }
    int win = 0;
    int draw = 0;
    int loss = 0;
    for (auto i = mono.begin(); i < mono.end(); i++){
        if (i < monoloss){
            loss += 1;
        } else if (i >= monowin){
            win += 1;
        } else{
            draw += 1;
        }
    }
    cout << win << " " << draw << " " << loss << "\n";
}

int main() {
    int t; cin >> t;
    for (int i = 0; i < t; i++){
        solve();
    }
}