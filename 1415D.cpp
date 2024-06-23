#include <bits/stdc++.h>

typedef long long i1;
using namespace std;
i1 powersoftwo[31];
i1 findgreatestdivisor(i1 x){
    for (i1 i = 0; i < 31; i++){
        if (x/powersoftwo[i] == 0){
            return i-1;
        }
    }
}
/*
int xxor(int x, int y){
    return x^y;
    return (x | y) & (!(x & y));
}
 */
int main() {
    i1 n; vector<i1> arr;
    cin >> n;
    for (i1 i = 0; i < n; i++){
        i1 temp;
        cin >> temp; arr.push_back(temp);
    }
    powersoftwo[0] = 1;
    for (i1 i = 1; i < 31; i++){
        powersoftwo[i] = powersoftwo[i-1]*2;
    }
    i1 coveredsofar = 0;
    i1 currentdivis = 0;
    for (i1 i = 0; i < n; i++){
        if (coveredsofar == 0){
            currentdivis = findgreatestdivisor(arr[i]);
            coveredsofar = 1;
        }
        else if (coveredsofar == 3){
            cout << 1;
            return 0;
        } else{
            if (findgreatestdivisor(arr[i]) == currentdivis){
                coveredsofar += 1;
            } else{
                coveredsofar = 1;
                currentdivis = findgreatestdivisor(arr[i]);
            }
        }
    }
    if (coveredsofar == 3){
        cout << 1;
        return 0;
    }

    i1 answer = INT_MAX;
    for (i1 i = 0; i < n; i++){
        i1 xorvalue = 0;
        for (i1 j = i; j < n; j++){
            xorvalue = xorvalue ^ arr[j];
            if (i != 0){
                if (xorvalue < arr[i-1]){
                    answer = min(answer, j-i);
                }
            }
            i1 newxorvalue = 0;
            for (i1 k = j+1; k < n; k++){
                newxorvalue ^= arr[k];
                if (j != n-1){
                    if (xorvalue > newxorvalue){
                        answer = min(answer, j-i + k-(j+1));
                    }
                }
            }
        }
    }
    if (answer != INT_MAX) {
        cout << answer;
    }else{
        cout << -1;
    }
}
