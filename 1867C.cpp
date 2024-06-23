#include <bits/stdc++.h>
using namespace std;
int solve(){
    int n; cin >> n;
    set<int> arr;
    for (int i = 0; i <  n; i++){
        int temp; cin >> temp;
        arr.insert(temp);
    }
    map<int,int> streaks;
    int currstreak = 1;
    int curron = *arr.begin();
    for (auto i = arr.begin(); i != arr.end(); i++){
        if (i == arr.begin()){
            continue;
        }
        if (*i != curron+currstreak){
            streaks[curron] = currstreak;
            currstreak = 1;
            curron = *i;
        } else{
            currstreak += 1;
        }
    }
    streaks[curron] = currstreak;
    if (streaks.begin()->first >= 1){
        cout << 0 << endl;
        int outcome; cin >> outcome;
        while (outcome != -1){
            if (outcome == -2){
                return 0;
            }
            cout << outcome << endl;
            cin >> outcome;
        }
        return 1;
    }
    int turnstaken = 0;
    cout << streaks.begin()->first + streaks.begin()->second << endl;
    int outcome; cin >> outcome;
    while (outcome != -1){
        if (outcome == -2){
            return 0;
        }
        cout << outcome << endl;
        cin >> outcome;
    }
    return 1;

}
int main() {
    int t; cin >> t; for (int i = 0; i < t; i++){
        int aaa = solve();
        if (!aaa){
            break;
        }
    }
}
