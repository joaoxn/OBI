// https://neps.academy/br/exercise/3580
// 100/100
// Iniciado: Sun Sep 27 11:46:17 2026
// Finalizado: Sun Sep 27 12:32:47 2026

#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)
#define fi first
#define se second
typedef pair<int,int> pii;

int n, m, k;
vector<int> pai;
vector<int> sz;

int find(int u) {
    if (pai[u] == u) return u;
    pai[u] = find(pai[u]);
    return pai[u];
}

bool unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;
    if (sz[u] > sz[v]) swap(u,v);
    pai[u] = v;
    sz[v] += sz[u];
    return true;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    pai.resize(n+1);
    sz.resize(n+1,1);
    for (int i = 1; i <= n; i++) pai[i] = i;

    queue<pii> q;
    bool hsimples = true;
    int rodos = 0;
    for (int i = 0; i < m; i++) {
        int a, b, t; cin >> a >> b >> t;
        if (t == 1) { // hidrovia
            if (!unite(a,b)) hsimples = false;
        } else { // rodovia
            q.push({a,b});
        }
    }

    if (!hsimples) {
        cout << "N\n";
        return 0;
    }

    int built = 0;
    while (!q.empty()) {
        pii u = q.front(); q.pop();
        if (!unite(u.fi,u.se)) built++;
    }

    cout << (built <= k ? 'S' : 'N') << '\n';
    return 0;
}