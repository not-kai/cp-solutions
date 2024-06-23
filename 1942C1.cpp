#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n,x; cin >> n >> x;
    int y; cin >> y;
    vector<int> arr(x);
    set<int> verticesleft;
    set<tuple<int,int,int>> triangles;
    for (int i = 0; i < x; i++){
        cin >> arr[i];
        verticesleft.insert(arr[i]);
    }
    int onvertex = *verticesleft.begin();
    while (verticesleft.size() > 2){
        auto erasedvertex = next(verticesleft.find(onvertex));
        if (erasedvertex == verticesleft.end()){
            erasedvertex = verticesleft.begin();
        }
        auto nextvertex = next(erasedvertex);
        if (nextvertex == verticesleft.end()){
            nextvertex = verticesleft.begin();
        }
        triangles.insert({onvertex, *erasedvertex, *nextvertex});
        if (onvertex - (*erasedvertex) == -2 || onvertex - (*erasedvertex) == n-2){
            triangles.insert({onvertex, (onvertex%n)+1, *erasedvertex});
        }if ((*erasedvertex) - (*nextvertex) == -2 || (*erasedvertex) - (*nextvertex) == n-2){
            triangles.insert({*erasedvertex, ((*erasedvertex)%n)+1, *nextvertex});
        }
        verticesleft.erase(*erasedvertex);
        onvertex = *nextvertex;
    }
    if (verticesleft.size() == 2 && ((*verticesleft.rbegin()) - (*verticesleft.begin()) == 2 || (*verticesleft.rbegin()) - (*verticesleft.begin()) == 2-n)){
        triangles.insert({*verticesleft.begin(), ((*verticesleft.begin())%n)+1, *verticesleft.rbegin()});
    }
    if (verticesleft.size() == 2 && ((*verticesleft.begin()) - (*verticesleft.rbegin()) == 2 || (*verticesleft.begin()) - (*verticesleft.rbegin()) == 2-n)){
        triangles.insert({*verticesleft.rbegin(), ((*verticesleft.rbegin())%n)+1, *verticesleft.begin()});
    }
    cout << triangles.size() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}