#include <bits/stdc++.h>
using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2

int t, n, m;
vector<set<int>> grafo;
vector<int> color;

bool dfs(int v) {
    color[v] = GRAY;
    for (int path : grafo[v]) {
        if (color[path] == GRAY) return true;
        if (color[path] == BLACK) continue;
        bool res = dfs(path);
        if (res) return true;
    }
    color[v] = BLACK;
    return false;
}

int main() {
    scanf("%d", &t);
    for (int _t = 0; _t < t; ++_t) {
        grafo.clear();
        color.clear();

        scanf("%d %d", &n, &m);
        grafo.resize(n+1);
        color.resize(n+1);

        for (int i = 0; i < m; ++i) {
            int a, b;
            scanf("%d %d", &a, &b);
            if (!grafo[a].count(b))
                grafo[a].insert(b);
        }
        bool temLoop = false;
        for (int i = 1; i <= n; i++) {
            if (color[i]) continue;
            if (dfs(i)) {
                temLoop = true;
                break;
            }
        }
        printf(temLoop ? "SIM\n" : "NAO\n");
    }

    return 0;
}
