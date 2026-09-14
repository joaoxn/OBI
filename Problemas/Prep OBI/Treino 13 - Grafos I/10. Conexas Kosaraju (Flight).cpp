// https://cses.fi/problemset/task/1682

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define IGN if (0) 
#define fi first
#define se second.first
#define th second.second
typedef pair<int,pair<int,int>> trio;
typedef long long ll;

int n, m;
vector<set<int>> g;
vector<set<int>> rg;
stack<int> ord;
vector<bool> vis;
vector<vector<int>> comps;

void order(int u) {
    if (vis[u]) return;
    vis[u] = true;
    for (int v : g[u]) {
        order(v);
    }
    ord.push(u);
}

void collect(int u, int root) {
    if (vis[u]) return;
    vis[u] = true;
    if (u == root) comps.push_back({u});
    else comps.back().push_back(u);

    for (int v : rg[u]) {
        collect(v, root);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    g.resize(n+1);
    rg.resize(n+1);
    vis.resize(n+1);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].insert(b);
        rg[b].insert(a);
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        order(i);
    }
    vis.clear();
    vis.resize(n+1);

    while (!ord.empty()) {
        int u = ord.top(); ord.pop();
        collect(u,u);
    }

    if (comps.size() <= 1) {
        cout << "YES";
    } else {
        cout << "NO\n";
        int a = comps[1][0], b = comps[0][0];
        cout << a << ' ' << b;
    }

    return 0;
}