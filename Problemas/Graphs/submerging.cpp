// Algoritmo de Trojan - Pontos de Articulação
// !INCOMPLETO
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<set<int>> grafo;
vector<int> discovery;
vector<int> low;
vector<bool> visited;
int gTime;
int articulations = 0;

void dfs(int v) {
    discovery[v] = gTime++;
    low[v] = discovery[v];
    for (int u : grafo[v]) {
        if (!visited[u])
            dfs(u);
        low[v] = min(low[v],low[u]);
        if (low[u] >= discovery[v])
            ++articulations;
    }

}

int main() {
    for (int t = 1; scanf("%d %d", &n, &m) > 0 && (n!=0 || m!=0); ++t) {
        grafo.clear();
        discovery.clear();
        low.clear();
        visited.clear();
        grafo.resize(n+1);
        discovery.resize(n+1);
        low.resize(n+1);
        visited.resize(n+1);
        gTime = 0;
        
        for (int i = 0; i < m; ++i) {
            int a, b;
            scanf("%d %d", &a, &b);
            grafo[a].insert(b);
            grafo[b].insert(a);
        }
        dfs(1);
        printf("%d\n",articulations);
    }

    return 0;
}