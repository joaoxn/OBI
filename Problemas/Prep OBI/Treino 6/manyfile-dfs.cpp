// distancia do vértice mais distante da origem de um subgrafo conexo
//? Wrong Answer (35%)
#include <bits/stdc++.h>
using namespace std;

int n;
vector<set<int>> grafo;
vector<bool> vis;

vector<int> cores;

bool temCiclos(int v) {
    cores[v] = 1;
    for (int u : grafo[v]) {
        if (cores[u] == 1) return true;
        if (cores[u] == 2) continue;

        if (temCiclos(u)) return true;

    }
    cores[v] = 2;
    return false;
}

int dfs(int v) {
    vis[v] = true;
    int max = 0;
    for (int u : grafo[v]) {
        if (vis[u]) continue;
        int depth = dfs(u);
        if (depth > max) max = depth;
    }
    return max + 1;
}

int main() {
    for (int t = 1; scanf("%d", &n) > 0 && (n!=0); ++t) {
        grafo.clear();
        grafo.resize(n+1);
        vis.clear();
        vis.resize(n+1);
        cores.clear();
        cores.resize(n+1);

        for (int i = 1; i <= n; ++i) {
            int m;
            scanf("%d", &m);
            for (int j = 1; j <= m; ++j) {
                int x;
                scanf("%d", &x);
                grafo[i].insert(x);
            }
        }

        
        int max = 0;
        for (int i = 1; i <= n; ++i) {
            if (cores[i] == 0) {
                if (temCiclos(i)) {
                    max = -1;
                    break;
                }
            }

            if (vis[i]) continue;
            int dist = dfs(i);
            if (dist > max) max = dist;
        }
        printf("%d\n", max);
    }

    return 0;
}