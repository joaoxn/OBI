// 100/100 - https://judge.beecrowd.com/pt/problems/view/2412
// Verificar conexidade de grafo não-dirigido (com distância entre pontos)
#include <bits/stdc++.h>
using namespace std;

int n, d;
vector<set<int>> grafo;

struct Point {
    int x, y;
};

Point arv[1001];

bool vis[1001];

void dfs(int u) {
    vis[u] = true;
    for (int v : grafo[u]) {
        if (!vis[v]) dfs(v);
    }
}

int main() {
    scanf("%d %d", &n, &d);
    grafo.resize(n);

    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        arv[i] = {x,y};
    }

    for (int i = 0; i < n; i++) {
        Point a1 = arv[i];
        for (int j = 0; j < n; j++) {
            Point a2 = arv[j];
            int dist = pow(a1.x-a2.x,2) + pow(a1.y-a2.y,2);
            if (dist <= d*d) {
                grafo[i].insert(j);
                grafo[j].insert(i);
            }
        }
    }

    dfs(0);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            printf("N\n");
            return 0;
        }
    }
    printf("S\n");
    return 0;
}