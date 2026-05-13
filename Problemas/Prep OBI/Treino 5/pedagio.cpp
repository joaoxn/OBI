#include <bits/stdc++.h>
using namespace std;

int c, e, l, p;

int main() {
    for (int t = 1; scanf("%d %d %d %d", &c, &e, &l, &p) > 0 && (c!=0 || e!=0 || l!=0 || p!=0); ++t) {
        vector<set<int>> grafo(c+1);
        vector<int> dist(c+1);
        
        for (int i = 0; i < e; ++i) {
            int x, y;
            scanf("%d %d", &x, &y);
            grafo[x].insert(y);
            grafo[y].insert(x);
        }
        
        printf("Teste %d\n", t);

        for (int i = 0; i < c+1; i++) {
            dist[i] = -1;
        }

        dist[l] = 0;

        queue<int> q;
        q.push(l);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int next : grafo[v]) {
                if (dist[next] != -1) continue;
                dist[next] = dist[v]+1;
                if (dist[next] > p) goto print;
                q.push(next);
            }
        }
        print:
        for (int i = 1; i <= c; i++) {
            if (0 < dist[i] && dist[i] <= p) {
                printf("%d ", i);
            }
        }
        printf("\n\n");
    }

    return 0;
}