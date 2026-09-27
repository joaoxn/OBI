// https://olimpiada.ic.unicamp.br/pratique/ps/2017/f3/arranhaceu/
// 100/100

#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)
typedef pair<int,int> pii;

int n;
vector<set<int>> g;
vector<int> sz;

void sizedfs(int u, int p) {
    if (g[u].empty()) {
        sz[u] = 1;
    } else for (int v : g[u]) {
        if (v == p) continue;
        sizedfs(v, u);
        sz[u] += sz[v];
    }
}

int minv = INT_MAX;
void dfs(int u, int p) {
    for (int v : g[u]) {
        if (v == p) continue;
        int diff = abs(n-2*sz[v]);
        minv = min(minv, diff);
        // if (diff == minv) {
        //     printf("%d-%d: %d (%d-%d)\n", u,v,diff,sz[u],sz[v]);
        // }
        dfs(v, u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    g.resize(n+1);
    sz.resize(n+1, 1);

    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }
    
    sizedfs(1,0);
    dfs(1,0);

    cout << minv;

    return 0;
}