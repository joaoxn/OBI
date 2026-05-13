#include <bits/stdc++.h>
using namespace std;

int n, k, d;
vector<set<int>> grafo;
vector<int> police;

int main() {
    scanf("%d %d %d", &n, &k, &d);
    grafo.resize(n+1);
    police.resize(k);
    for (int i = 0; i < k; ++i) {
        scanf("%d", &police[i]);
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        grafo[u].insert(v);
        grafo[v].insert(u);
    }

    // BFS Multi-source + detecção de arestas removíveis
    // Como resolver?

    return 0;
}