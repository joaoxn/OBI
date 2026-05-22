#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<set<int>> grafo;
int grau[200001];

int main() {
    scanf("%d %d", &n, &m);
    grafo.resize(n+2);
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        grafo[a].insert(b);
        ++grau[b];
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (grau[i] == 0)
            q.push(i);
    }

    vector<int> sol;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : grafo[v]) {
            --grau[u];
            if (grau[u] == 0) {
                q.push(u);
            }
        }
        sol.push_back(v);
    }
    for (int i = 1; i <= n; ++i) {
        if (grau[i] != 0) {
            printf("IMPOSSIBLE\n");
            return 0;
        }
    }
    // if (sol.size() < n)
    //     printf("IMPOSSIBLE");
    // else 
    for (int v : sol)
        printf("%d ", v);
    
    printf("\n");

    return 0;
}