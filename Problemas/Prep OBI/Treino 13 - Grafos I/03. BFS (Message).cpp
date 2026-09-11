#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)

int n, m;
vector<set<int>> g;
vector<int> orig;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    g.resize(n+1);
    orig.resize(n+1);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }

    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == n) break;

        for (int v : g[u]) {
            if (orig[v] != 0) continue;
            q.push(v);
            orig[v] = u;
        }
    }

    if (orig[n] == 0) {
        cout << "IMPOSSIBLE";
    } else {
        int v = n;
        vector<int> path;
        while (v != 1) {
            path.push_back(v);
            v = orig[v];
        }
        path.push_back(1);

        cout << path.size() << '\n';
        for (int i = path.size()-1; i >= 0; i--) cout << path[i] << ' ';
    }

    return 0;
}
