#include <bits/stdc++.h>

typedef long long i;
using namespace std;
int main() {
    i n,k;
    cin >> n >> k;
    if (k == n){
        cout << 1;
        return 0;
    } else if (k == n-1){
        cout << 2;
        return 0;
    } else if (k == 1){
        cout << n;
        return 0;
    } else if (k == 2){
        if (n%2 == 0){
            cout << n-2;
            return 0;
        } else{
            cout << n-1;
            return 0;
        }
    }
    vector<i> state = {n, 2, 1}; //max#, even, last
    if (n%2 == 1){
        state[2] = 0;
        state[0] = n+1;
    }
    ///cout << "state " << state[0] << ": " << state[1] << " " << state[2] << endl;
    while (state[0] > 1){
        i new0, new1, new2;
        new1 = (state[1]+1)*2;
        new0 = state[0]/2;
        if (new0%2 == 0){
            new2 = 1 + state[2] + (state[1]/2);
        }
        else{
            new0 -= 1;
            new2 = 2 + state[2] + (state[1]);
        }
        state[0] = new0;
        state[1] = new1;
        state[2] = new2;
        ///cout << "state " << state[0] << ": " << state[1] << " " << state[2] << endl;
        if (k <= state[2]){
            cout << state[0]; return 0;
        } else if (k <= state[1]/2) {
            cout << state[0] - 1; return 0;
        } else if (k <= state[1]){
            if (state[0] > 4){
                cout << state[0] - 2; return 0;
            }
        }
    }
}
