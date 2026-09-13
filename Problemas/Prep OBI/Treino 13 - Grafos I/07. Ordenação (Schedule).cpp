#include <bits/stdc++.h>
using namespace std;

#define IGN if (0) 

int n, m;
vector<set<int>> g;
vector<int> q;
int qp = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    g.resize(n+1);

    vector<int> indeg(n+1);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        if (g[a].find(b) != g[a].end()) continue;
        g[a].insert(b);
        indeg[b]++;
    }

    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) q.push_back(i); 
    }

    while (qp < q.size()) {
        int u = q[qp++];

        for (int v : g[u]) {
            indeg[v]--;
            if (indeg[v] <= 0) q.push_back(v);
        }
    }

    if (q.size() < n) cout << "IMPOSSIBLE";
    else {
        for (int x : q) cout << x << ' ';
    }

    return 0;
}