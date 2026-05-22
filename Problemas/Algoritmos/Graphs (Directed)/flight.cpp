// Accepted - 20/20
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<set<int>> graph;
vector<set<int>> graphOpp;
int visited[100001];

void dfs(int v) {
    visited[v] = true;
    for (int u : graph[v]) {
        if (!visited[u])
            dfs(u);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    graph.resize(n+1);
    graphOpp.resize(n+1);

    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].insert(b);
        graphOpp[b].insert(a);
    }

    int start=1,end=-1;

    dfs(1);
    bool conexo = true;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            conexo = false;
            end = i;
            break;
        }
    }
    if (conexo) {
        graph = graphOpp;
        memset(visited, false, sizeof visited);
        dfs(1);
        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                conexo = false;
                start = i;
                end = 1;
                break;
            }
        }
    }

    printf(conexo ? "YES" : "NO");
    printf("\n");
    if (!conexo)
        printf("%d %d\n", start, end);

    return 0;
}