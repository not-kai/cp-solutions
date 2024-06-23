#include <iostream>

typedef long long i1;
using namespace std;
int main() {
    i1 testcases;
    cin >> testcases;
    for (i1 i = 0; i < testcases; i++){
        i1 monsters;
        cin >> monsters;
        i1 answer = 0;
        for (i1 j = 0; j < monsters; j++){
            i1 health;
            cin >> health;
            answer += health;
        }
        i1 maxmonster;
        for (i1 j = 0; j < monsters; j++){
            i1 monster;
            if (j == 0){
                cin >> monster;
                maxmonster = monster;
            } else{
                cin >> monster;
                if (monster < maxmonster){
                    answer += monster;
                } else{
                    answer += maxmonster;
                    maxmonster = monster;
                }
            }
        }
        cout << answer << endl;
    }
}
