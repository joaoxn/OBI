#include <bits/stdc++.h>
using namespace std;

int t, n;
vector<int> grafo;
vector<set<int>> grafoOpp;
vector<int> depth;

int dfs(int v) {
    int max = 0;
    for (int u : grafoOpp[v]) {
        if (!depth[u])
            dfs(u);
        if (depth[u] > max) max = depth[u];
    }
    depth[v] = max + 1;
    return max + 1;
}

int countPeople(int v) {
    int people;
    for (people = 1;; ++people) {
        vis[v] = true;
        if (vis[grafo[v]]) break;
        v = grafo[v];
    }
    return people + dfs(v);
}

int main() {
    scanf("%d", &t);
    for (int _t = 1; _t <= t; ++_t) {
        scanf("%d", &n);
        grafo.clear();
        grafo.resize(n+1);
        grafoOpp.clear();
        grafoOpp.resize(n+1);
        vis.clear();
        vis.resize(n+1);

        for (int i = 0; i < n; ++i) {
            int a, b;
            scanf("%d %d", &a, &b);
            grafo[a] = b;
            grafoOpp[b].insert(a);
        }
        int max = 1;
        for (int i = 1; i <= n; ++i) {
            int ppl = countPeople(i);
            if (ppl > max) max = ppl;
        }
    }

    return 0;
}