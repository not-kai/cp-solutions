#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n; cin >> n;
    int answer = 0;
    for (int value = n; value >= 1; value--){
        for (int index = n; index >= 1; index--){
            if ((n-1)*(index*value) < answer){
                break;
            }
            set<int> numbers;
            for (int i = 1; i <= n; i++){
                if (i != value){
                    numbers.insert(i);
                }
            }
            bool possible = true;
            int tempanswer = 0;
            for (int onindex = n; onindex >= 1; onindex--){
                if (onindex == index){
                    continue;
                }
                int searchfor = (value*index)/onindex;
                auto iter = numbers.upper_bound(searchfor);
                if (iter == numbers.begin()){
                    possible = false;
                    break;
                } else{
                    iter--;
                    tempanswer += (*iter) * onindex;
                    numbers.erase(*iter);
                }
            }
            if (possible){
                answer = max(answer, tempanswer);
            } else{
                break;
            }
        }
    }
    cout << answer << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}
