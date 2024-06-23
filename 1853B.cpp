#include <bits/stdc++.h>
using namespace std;
long long fibsequence[200003];
void solve(){
    int n,k; cin >> n >> k;
    if (k > 200002){
        cout << 0 << "\n"; return;
    }
    if (k > n && fibsequence[k] > n){
        cout << 0 << "\n"; return;
    }
    int a,b;
    b = fibsequence[k];
    a = fibsequence[k-1];
    int numbera;
    int numberb = 0;
    int tempn = n;
    while (tempn%a != 0 && tempn > 0){
        tempn -= b;
        numberb += 1;
    }
    if (tempn < 0){
        cout << 0 << "\n";
        return;
    }
    numbera = tempn/a;
    while (numbera > numberb){
        numbera -= b;
        numberb += a;
    }
    if (numbera < 0){
        cout << 0 << "\n";
        return;
    }

    int numbera2 = 0;
    int numberb2;
    int tempn2 = n;
    while (tempn2%b != 0 && tempn2 > 0){
        tempn2 -= a;
        numbera2 += 1;
    }
    numberb2 = tempn2/b;
    cout << (numbera-numbera2)/(b) + 1 << "\n";


}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fibsequence[0] = 0;
    fibsequence[1] = 0;
    fibsequence[2] = 1;
    for (int i = 3; i < 200003; i++){
        fibsequence[i] = fibsequence[i-1] + fibsequence[i-2];
        if (fibsequence[i] > 99999999999){
            for (int j = i; j < 200003; j++){
                fibsequence[j] = 99999999999;
            }
            break;
        }
    }
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }

}
