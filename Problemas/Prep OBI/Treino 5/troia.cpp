#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<set<int>> grafo;
int family[1000001];

void dfs(int v, int owner) {
    family[v] = owner;
    for (int next : grafo[v]) {
        if (family[next] == 0)
            dfs(next, owner);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    grafo.clear();
    grafo.resize(n+1);

    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        grafo[a].insert(b);
        grafo[b].insert(a);
    }

    int count = 0;
    for (int i = 1; i <= n; ++i) {
        if (family[i] != 0) continue;
        ++count;
        dfs(i, i);
    }

    printf("%d\n", count);

    return 0;
}