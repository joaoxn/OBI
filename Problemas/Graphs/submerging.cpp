// Algoritmo de Trojan - Pontos de Articulação
// !INCOMPLETO
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<set<int>> grafo;
vector<int> discovery;
vector<int> low;
vector<int> parent;
vector<bool> visited;
int gTime;
set<int> articulations;

void dfs(int v) {
    visited[v] = true;
    discovery[v] = gTime++;
    low[v] = discovery[v];
    for (int u : grafo[v]) {
        if (parent[v] == u) continue;
        if (!visited[u]) {
            parent[u] = v;
            dfs(u);
        }
        low[v] = min(low[v],low[u]);
        if (low[u] >= discovery[v])
            articulations.insert(v);
    }

}

int main() {
    for (int t = 1; scanf("%d %d", &n, &m) > 0 && (n!=0 || m!=0); ++t) {
        grafo.clear();
        discovery.clear();
        low.clear();
        visited.clear();
        parent.clear();
        grafo.resize(n+1);
        discovery.resize(n+1);
        low.resize(n+1);
        visited.resize(n+1);
        parent.resize(n+1);
        gTime = 0;
        
        for (int i = 0; i < m; ++i) {
            int a, b;
            scanf("%d %d", &a, &b);
            grafo[a].insert(b);
            grafo[b].insert(a);
        }
        dfs(1);
        printf("%d\n",articulations.size());
    }

    return 0;
}

/*
8 9

1 2
1 3
2 3
3 4
4 5
5 6
5 7
6 7
6 8
0 0

4
*/