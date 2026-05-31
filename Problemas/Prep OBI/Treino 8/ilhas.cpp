// 100/100 - https://judge.beecrowd.com/pt/problems/view/2784
// Dijkstra
#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX

int n, m, s;
vector<set<pair<int,int>>> grafo;
int dist[1001];
bool vis[1001];

int main() {
    scanf("%d %d", &n, &m);
    grafo.resize(n+1);

    for (int i = 0; i <= n; i++) dist[i] = INF;
    
    for (int i = 0; i < m; i++) {
        int u, v, p;
        scanf("%d %d %d", &u, &v, &p);
        grafo[u].insert({v, p});
        grafo[v].insert({u, p});
    }
    scanf("%d", &s);
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0,s});
    dist[s] = 0;

    while (!q.empty()) {
        auto x = q.top(); q.pop();
        int u = x.second;
        if (vis[u]) continue;
        vis[u] = true;

        for (auto a : grafo[u]) {
            if (vis[a.first]) continue;
            int newdist = dist[u]+a.second;
            if (newdist >= dist[a.first]) continue;
            dist[a.first] = newdist;
            q.push({dist[a.first],a.first});
        }
    }

    int min = INF, max = 0;
    for (int i = 1; i <= n; i++) {
        if (i == s) continue;
        if (dist[i] < min) min = dist[i];
        if (dist[i] > max) max = dist[i];
    }
    printf("%d\n", max-min);
}
/*
4 5
2 1 5
1 3 4
2 3 6
4 2 8
3 4 12
1

6 11
1 2 3
6 1 9
2 6 10
2 3 8
5 3 3
4 3 2
2 4 12
6 4 1
4 5 9
1 5 16
5 6 5
5
*/