#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
typedef long long i1;
i1 powersoftwo[31];
i1 grr(i1 base, i1 power){
    return powersoftwo[power];

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i1 n; cin >> n;
    vector<i1> arr(n);
    for (i1 i = 0; i < n; i++){
        cin >> arr[i];
    }
    powersoftwo[0] = 1;
    for (int i = 1; i <= 30; i++){
        powersoftwo[i] = (powersoftwo[i-1]*2)%MOD;
    }


    i1 total = 0;
    for (i1 bit = 30; bit >= 0; bit--){
        i1 oddsum = 0;
        i1 oddinstances = 0;
        i1 evensum = 0;
        i1 eveninstances = 0;
        i1 onessofar = 0;
        for (i1 i = 0; i < n; i++){
            if (!((arr[i] >> bit) & 1)){
                if (onessofar%2 == 1){
                    evensum += i;
                    eveninstances += 1;
                    total += (((oddinstances)*(i+1)-oddsum)%MOD)*grr(2,bit)%MOD;
                } else{
                    oddinstances += 1;
                    oddsum += i;total += (((eveninstances)*(i+1)-evensum)%MOD)*grr(2, bit)%MOD;
                }
                total %= MOD;
                continue;
            }
            onessofar += 1;
            if (onessofar%2 == 1){
                oddinstances += 1;
                oddsum += i;
                total += (((oddinstances)*(i+1)-oddsum)%MOD)*grr(2,bit)%MOD;
            } else{
                evensum += i;
                eveninstances += 1;
                total += (((eveninstances)*(i+1)-evensum)%MOD)*grr(2, bit)%MOD;
            }
            total %= MOD;
        }
    }
    cout << total%MOD << "\n";
}

