#include <bits/stdc++.h>
using namespace std;
void solve() {

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q; cin >> n >> q;
    set<int> piles;
    for (int i = 0; i < n; i++){
        int temp; cin >> temp; piles.insert(temp);
    }
    multiset<int> maxdist;
    for (auto i = piles.begin(); i != piles.end(); i++){
        if (i == piles.begin()){
            continue;
        }
        maxdist.insert((*i) - (*(prev(i))));
    }
    if (piles.size() < 3){
        cout << 0 << "\n";
    } else{
        cout << *(piles.rbegin()) - *(piles.begin()) - *(maxdist.rbegin()) << "\n";
    }
    for (int aaa = 0; aaa < q; aaa++){
        int type,place; cin >> type >> place;
        if (type == 0){
            if (piles.size() == 1){
                piles.erase(piles.begin());
                cout << 0 << "\n";
                continue;
            }
            if (place == *(piles.begin())){
                maxdist.erase(maxdist.find(*(next(piles.begin())) - *(piles.begin())));
                piles.erase(place);
            } else if (place == *(piles.rbegin())){
                maxdist.erase(maxdist.find(*(piles.rbegin()) - *(next(piles.rbegin()))));
                piles.erase(place);
            } else{
                auto higher = piles.upper_bound(place);
                auto lower = prev(piles.lower_bound(place));
                maxdist.erase(maxdist.find(*higher - place));
                maxdist.erase(maxdist.find(place - *lower));
                maxdist.insert(*higher - *lower);
                piles.erase(place);
            }
        } else{
            if (piles.empty()){
                piles.insert(place);
                cout << 0 << "\n";
                continue;
            } else if (piles.size() == 1){
                piles.insert(place);
                maxdist.insert(*(piles.rbegin()) - *(piles.begin()));
                cout << 0 << "\n";
                continue;
            }
            auto higher = piles.upper_bound(place);
            auto lower = (piles.lower_bound(place));
            if (lower == piles.begin()){
                maxdist.insert(*(piles.begin()) - place);
                piles.insert(place);
            } else if (higher == piles.end()){
                maxdist.insert(place - *(piles.rbegin()));
                piles.insert(place);
            }
            lower = prev(lower);
            maxdist.insert(*higher - place);
            maxdist.insert(place - *lower);
            maxdist.erase(maxdist.find(*higher-*lower));
            piles.insert(place);
        }
        if (piles.size() < 3){
            cout << 0 << "\n";
        } else {
            cout << *(piles.rbegin()) - *(piles.begin()) - *(maxdist.rbegin()) << "\n";
        }
    }
}