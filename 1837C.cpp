#include <bits/stdc++.h>
using namespace std;
void solve(){
    string x;
    getline(cin, x);
    int questionmarks = 0;
    int lastvalueleft = -1;
    for (int i = 0; i < x.size(); i++){
        if (x.at(i) == '1'){
            for (int i = 0; i <= questionmarks; i++){
                    cout << "1";
                }
            lastvalueleft = '1';
            questionmarks = 0;
        } else if (x.at(i) == '0'){
                for (int i = 0; i <= questionmarks; i++){
                    cout << "0";
                }
            lastvalueleft = '0';
            questionmarks = 0;
        } else{
           questionmarks += 1;
        }
    }
    if (questionmarks != 0){
        if (lastvalueleft == '0') {
            for (int i = 0; i < questionmarks; i++) {
                cout << "0";
            }
        } else{
            for (int i = 0; i < questionmarks; i++){
                cout << "1";
            }
        }
    }
    cout << "\n";
}
int main() {
    int testcases;
     cin >> testcases;
     string temp;
    getline(cin, temp);
     for (int i = 0; i < testcases; i++){
         solve();
     }
}
