#include <bits/stdc++.h>
using namespace std;

int n;
vector<set<int>> grafo;

int dfs_depth(int v, int p) {
    int max_d = 0;
    for (int u : grafo[v]) {
        if (u == p) continue;
        int depth = dfs_depth(u,v);
        if (depth > max_d) max_d = depth;
    }
    return max_d + 1;
}

int depth_goal;

int dfs_find(int v, int p, int depth=1) {
    if (depth == depth_goal) return v;
    for (int u : grafo[v]) {
        if (u == p) continue;
        int k = dfs_find(u,v,depth+1);
        if (k != -1) return k;
    }
    return -1;
}

int main() {
    scanf("%d", &n);
    grafo.resize(n+1);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        grafo[a].insert(b);
        grafo[b].insert(a);
    }

    // assumir que a raiz é 1; achar o mais distante: esse será uma das pontas
    // achar a outra ponta a partir da ponta obtida

    depth_goal = dfs_depth(1,-1);
    int k = dfs_find(1, -1);

    int diameter = dfs_depth(k,-1);
    printf("%d\n", diameter-1);

    return 0;
}