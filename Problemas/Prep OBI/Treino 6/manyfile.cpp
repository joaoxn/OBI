// 100/100 - https://judge.beecrowd.com/pt/problems/view/2545
// Ordenação Topológica - Algoritmo de Kahn
#include <bits/stdc++.h>
using namespace std;

int n;
vector<set<int>> grafo;
vector<int> cores;
int grau[1001];
int dist[1001];

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

int main() {
    for (int t = 1; scanf("%d", &n) > 0 && (n!=0); ++t) {
        grafo.clear();
        grafo.resize(n+1);
        cores.clear();
        cores.resize(n+1);
        memset(grau, 0, sizeof grau);
        memset(dist, 0, sizeof dist);

        for (int i = 1; i <= n; ++i) {
            int m;
            scanf("%d", &m);
            for (int j = 1; j <= m; ++j) {
                int x;
                scanf("%d", &x);
                grafo[i].insert(x);
                grau[x]++;
            }
        }
        
        // Identificação de ciclos
        int maxv = 0;
        for (int i = 1; i <= n; ++i) {
            if (cores[i] == 0) {
                if (temCiclos(i)) {
                    maxv = -1;
                    break;
                }
            }
        }
        if (maxv == -1) {
            printf("-1\n");
            continue;
        }

        // BFS Multi-source
        queue<int> q;

        for (int i = 1; i <= n; ++i) {
            if (grau[i] == 0) {
                q.push(i);
                dist[i] = 1;
            }
        }
        
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int u : grafo[v]) {
                if (--grau[u] == 0) {
                    q.push(u);
                    dist[u] = dist[v]+1;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if (dist[i] > maxv) maxv = dist[i];
        }

        printf("%d\n", maxv);
    }

    return 0;
}