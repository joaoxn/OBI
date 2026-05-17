#include <bits/stdc++.h>
using namespace std;

int e, l;
vector<set<int>> grafo;
bool vis[101];

void dfs(int v) {
    vis[v] = true;
    for (int u : grafo[v]) {
        // printf("%d-%d\n",v,u);
        if (!vis[u])
            dfs(u);
    }
}

int main() {
    for (int t = 1; scanf("%d %d", &e, &l) > 0 && (e!=0 || l!=0); ++t) {
        grafo.clear();
        grafo.resize(e+1);
        memset(vis, false, sizeof vis);

        for (int i = 0; i < l; ++i) {
            int x, y;
            scanf("%d %d", &x, &y);
            grafo[x].insert(y);
            grafo[y].insert(x);
        }
        dfs(1);
        printf("Teste %d\n", t);
        bool falha = false;
        for (int i = 1; i <= e; ++i) {
            if (!vis[i]) {
                falha = true;
                break;
            }
        }
        printf(falha ? "falha\n\n" : "normal\n\n");
    }

    return 0;
}