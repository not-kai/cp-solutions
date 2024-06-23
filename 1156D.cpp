#include <bits/stdc++.h>
using namespace std;
unordered_map<int, unordered_set<int>> zeros;
unordered_map<int, unordered_set<int>> ones;
int n;
const int MAXN = 200001;
namespace A{
        int dsu[200000+1], rank[200000+1], size[200001];
        int n;
        int connectedcomponents;
        int getParent(int x){
            if (dsu[x]==x){
                return x;
            }
            dsu[x] = getParent(dsu[x]);
            return dsu[x];
        }
        int getSize(int x){
            if (dsu[x]==x){
                return size[x];
            }
            dsu[x] = getParent(dsu[x]);
            return size[dsu[x]];
        }
        void uniteSets(int x, int y){
            int parent1(getParent(x)), parent2(getParent(y));
            if (parent1 == parent2){
                return;
            }
            if (rank[parent1] < rank[parent2]){
                swap(parent1, parent2);
            }
            dsu[parent2] = parent1;
            rank[parent1] = max(rank[parent1], rank[parent2]+1);
            size[parent1] += size[parent2];
            connectedcomponents -= 1;
        }
        bool sameSet(int x, int y){
            return (getParent(x) == getParent(y));
        }
        void initialize(int maxn){
            n = maxn;
            connectedcomponents = n;
            for (int i = 1; i <= n; i++){
                dsu[i] = i;
                rank[i] = 1;
                size[i] = 1;
            }
        }
}
namespace B{
    int dsu[200000+1], rank[200000+1], size[200001];
    int n;
    int connectedcomponents;
    int getParent(int x){
        if (dsu[x]==x){
            return x;
        }
        dsu[x] = getParent(dsu[x]);
        return dsu[x];
    }
    int getSize(int x){
        if (dsu[x]==x){
            return size[x];
        }
        dsu[x] = getParent(dsu[x]);
        return size[dsu[x]];
    }
    void uniteSets(int x, int y){
        int parent1(getParent(x)), parent2(getParent(y));
        if (parent1 == parent2){
            return;
        }
        if (rank[parent1] < rank[parent2]){
            swap(parent1, parent2);
        }
        dsu[parent2] = parent1;
        rank[parent1] = max(rank[parent1], rank[parent2]+1);
        size[parent1] += size[parent2];
        connectedcomponents -= 1;
    }
    bool sameSet(int x, int y){
        return (getParent(x) == getParent(y));
    }
    void initialize(int maxn){
        n = maxn;
        connectedcomponents = n;
        for (int i = 1; i <= n; i++){
            dsu[i] = i;
            rank[i] = 1;
            size[i] = 1;
        }
    }
}
int main() {
    cin >> n;
    A::initialize(n);
    B::initialize(n);
    for (int i = 0; i < n-1; i++){
        int a, b, w;
        cin >> a >> b >> w;
        if (w == 0){
            zeros[a].insert(b);
            zeros[b].insert(a);
            A::uniteSets(a,b);

        } else{
            ones[a].insert(b);
            ones[b].insert(a);
            B::uniteSets(a,b);
        }
    }
    unordered_set<int> componentsones;
    unordered_map<int,pair<long long,long long>> componentszeros;
    unordered_set<int> idk;
    long long answer = 0;
    for (int i = 1; i <= n; i++){
        componentsones.insert(B::getParent(i));
    }
    for (int i : componentsones){
        answer += ((long long) B::getSize(i))*((long long) B::getSize(i));
        answer -= B::getSize(i); //remove 1 -> 1 paths
    }
    for (int i = 1; i <= n; i++){
        idk.insert(A::getParent(i));
        componentszeros[A::getParent(i)].first = A::getSize(A::getParent(i));
        componentszeros[A::getParent(i)].second += B::getSize(i) - 1;
    }
    for (int i : idk){
        answer += (componentszeros[i].first) * (componentszeros[i].second + componentszeros[i].first);
        answer -= componentszeros[i].first;
        answer -= componentszeros[i].second;
    }
    cout << answer << "\n";



}
