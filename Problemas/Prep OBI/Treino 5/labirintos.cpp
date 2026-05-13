#include <bits/stdc++.h>
using namespace std;

int t, n, v, a;

int main() {
    scanf("%d", &t);
    for (int _t = 0; _t < t; ++_t) {
        scanf("%d", &n);
        scanf("%d %d", &v, &a);
        vector<set<int>> grafo(v+1);
        int sol = 0;
        for (int i = 0; i < a; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            if (grafo[x].count(y)) continue;
            grafo[x].insert(y);
            grafo[y].insert(x);
            ++sol;
        }
        printf("%d\n", sol*2);
    }

    return 0;
}