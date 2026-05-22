// 100/100 - https://judge.beecrowd.com/pt/runs/code/49087711
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<set<int>> grafo;

int main() {
    scanf("%d %d", &n, &m);
    grafo.resize(n);
    int grau[n];
    memset(grau, 0, sizeof grau);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        grafo[a].insert(b);
        grau[b]++;
    }

    priority_queue<int, vector<int>, greater<int>> q;
    
    for (int i = 0; i < n; i++) {
        if (grau[i] == 0) q.push(i);
    }
    vector<int> sol;
    while (!q.empty()) {
        int u = q.top(); q.pop();

        for (int v : grafo[u]) {
            grau[v]--;
            if (grau[v] == 0) {
                q.push(v);
            }
        }
        sol.push_back(u);
    }
    if (sol.size() != n) printf("*\n");
    else for (int u : sol)
        printf("%d\n", u);

    return 0;
}