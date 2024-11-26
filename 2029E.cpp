#include <bits/stdc++.h>

using namespace std;
#define MAXN 400000
namespace SieveOfEratosthenes{
    std::vector <int> prime;
    bool is_composite[MAXN+1];
    vector<int> smallestprime(MAXN+1);
    void sieve (int n) {
        std::fill (is_composite, is_composite + n, false);
        for (int i = 2; i <= n; i++){
            smallestprime[i] = i;
        }
        for (int i = 2; i <= n; ++i) {
            if (!is_composite[i]) prime.push_back (i);
            for (int j = 2; i * j <= n; ++j) {
                is_composite[i * j] = true;
                smallestprime[i*j]=min(smallestprime[i*j],i);
            }
        }
    }
} //O(nlogn), can modify to get the smallest/greatest prime factor easily, which lets you do factorization in log(n) instead of sqrt(n) worst case
void solve() {
    int n; cin >> n;
    int numberofprimes = 0;
    int prime = 0;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        if (!SieveOfEratosthenes::is_composite[arr[i]]){
            numberofprimes += 1;
            prime = arr[i];
        }
    }
    if (numberofprimes >= 2){
        cout << -1 << "\n";
        return;
    } else if (numberofprimes == 0){
        cout << 2 << "\n";
        return;
    }
    for (int i = 0; i < n; i++){
        if (arr[i] == prime){
            continue;
        }
        if (arr[i]%prime == 0){
            continue;
        }
        bool works = false;
        int temp = arr[i];
        while (temp != 1){
            int smallest = SieveOfEratosthenes::smallestprime[temp];
            if (2*(1+(prime/smallest)) <= arr[i]/smallest){
                works = true;
                break;
            }
            while (temp%smallest == 0){
                temp /= smallest;
            }
        }
        if (!works){
            cout << -1 << "\n";
            return;
        }
    }
    cout << prime << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    SieveOfEratosthenes::sieve(400000);
    int t; cin >> t; for (int i = 0; i < t; i++){
        solve();
    }
}
