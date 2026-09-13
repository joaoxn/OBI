// TLE

#include <bits/stdc++.h>
using namespace std;

#define IGN if (0) 

int n, m;
vector<set<int>> g;
vector<set<int>> rev;
vector<int> deps;

void dfs(int u) {
    if (deps[u] > 0) return;

    int maxv = 0;
    for (int v : rev[u]) {
        dfs(v);
        if (deps[v] > maxv) maxv = deps[v];
    }
    deps[u] = maxv+1;
}

vector<int> vis;
bool cycle(int u) {
    if (vis[u] == 1) return true;
    vis[u] = 1;
    for (int v : g[u]) {
        if (cycle(v)) return true;
    }
    vis[u] = 2;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    g.resize(n+1);
    rev.resize(n+1);
    deps.resize(n+1);
    vis.resize(n+1);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].insert(b);
        rev[b].insert(a);
    }

    for (int x = 1; x <= n; x++) {
        if (vis[x] == 2) continue;
        if (cycle(x)) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }

    vector<int> tail;

    for (int i = 1; i <= n; i++) {
        if (g[i].empty()) tail.push_back(i); 
    }

    for (int x : tail) {
        dfs(x);
    }

    vector<pair<int,int>> ord;
    for (int i = 1; i <= n; i++) {
        ord.push_back({deps[i],i});
    }
    sort(ord.begin(),ord.end());
    
    for (auto x : ord) {
        cout << x.second << ' ';
    }

    return 0;
}