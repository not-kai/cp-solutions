/*
 * solution notes:
 * ok so basically: the main kickers are checking what happens from r-y-x+1 to r-y (these are the values where after
 *                                                                                  adding y to one of these, it eventually goes back to one of them)
 * so anyways yeah, just for each value, see where it goes and how long it takes
 * also if x > y then the value will eventually go to below 0, just find out how long it takes
 *
 */

#include <bits/stdc++.h>

typedef long long i1;
using namespace std;
int main() {
    long long k,l,r,t,x,y;
    cin >> k >> l >> r >> t >> x >> y;
    r -= l;
    k -= l;
    l = 0;
    unordered_map<i1,pair<i1,i1>> graph;
    for (i1 i = r-y-x+1; i <= r-y; i++){
        if (i < 0){
            graph[i] = {-1,0};
            continue;
        }
        if (x > y){
            graph[i] = {-1, (i/(x-y))+1};
            continue;
        } else{
            i1 temp = i;
            temp += y;
            temp -= x;
            i1 weight = 1;
            if (temp > r-y) {
                if (temp - (r - y) % x == 0) {
                    weight += max(0LL, (temp - (r - y)) / x);
                } else {
                    weight += max(0LL, 1 + ((temp - (r - y)) / x));
                }
            }
            temp -= (weight-1)*x;
            if (temp < 0){
                temp = -1;
            }
            graph[i] = {temp, weight};
        }
    }
    //case 1: x > y (each day loses water)
    //subcase 1: k is already less than r-y-x+1: just subtract and get days before it becomes 0
    //subcase 2: k is greater than r-y: subtract until r-y is achieved

    //case 2: x = y
    //this is always YES unless k+y > r AND k-x < 0

    //case 3: y > x (water increases until it reaches r-y+1 .... r)
    // if greater than r-y: just subtract x's until it falls in range
    // if less than r-y-x+1: add y's until it goes above r-y-x+1, and check if it becomes the first case or if it stays in the range

    //for all of these, must check how long it takes (if it's more than or equal to t, it's YES regardless of the graph)

    //after i get into that range, i keep track of t, and basically check whether i reach t first (YES), form a cycle (YES), or reach -1 first (NO)

    if (x == y){
        if (k+y > r && k-x < 0){
            cout << "No" << "\n";
            return 0;
        } else{
            cout << "Yes" << "\n";
            return 0;
        }
    } else if (x > y){
        if (k < r-y-x+1){
            i1 difference = x-y;
            if (t > (k/difference)+1){
                cout << "No" << "\n";
                return 0;
            } else{
                cout << "Yes" << "\n";
                return 0;
            }
        } else if (k > r-y){
            long long oldk = k;
            k -= x*(t-max(0LL,t-((k-(r-y+1))/(x)+1)));
            t = max(0LL,t-((oldk-(r-y+1))/(x)+1));
        }
    } else{
        if (k > r-y){
            long long oldk = k;
            k -= x*(t-max(0LL,t-((k-(r-y+1))/(x)+1)));
            t = max(0LL,t-((oldk-(r-y+1))/(x)+1));
        } else if (k < r-y-x+1){
            long long oldk = k;
            k += (t-max(0LL,t-((r-y-x-k)/(y-x))-1))*(y-x); //changed +1 to -1
            t = max(0LL,t-((r-y-x-oldk)/(y-x))-1);
        }
    }
    if (t == 0 && k >= 0){
        cout << "Yes" << "\n";
        return 0;
    } else if (k < 0){
        cout << "No" << "\n";
        return 0;
    }

    unordered_set<i1> cycle;
    cycle.insert(k);
    while (true){
        i1 sizebefore = cycle.size();
        if (t >= graph[k].second){
            cycle.insert(graph[k].first);
            t -= graph[k].second;
            k = graph[k].first;
        } else{
            cout << "Yes" << "\n";
            return 0;
        }
        if (k <= -1){
            cout << "No" << "\n";
            return 0;
        }
        if (cycle.size() == sizebefore){
            cout << "Yes" << "\n";
            return 0;
        }
    }

}
