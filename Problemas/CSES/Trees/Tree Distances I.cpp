#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)

int n;
vector<set<int>> g;
vector<int> dist;

pair<int,int> furthest(int u, int p, bool save) {
    int maxv = 0;
    int i = u;
    for (int v : g[u]) {
        if (v == p) continue;
        pair<int,int> fv = furthest(v,u, save);
        fv.first++;
        if (fv.first > maxv) {
            maxv = fv.first;
            i = fv.second;
        }
    }
    if (save)
    dist[u] = max(dist[u], maxv);
    return {maxv,i};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    g.resize(n+1);
    dist.resize(n+1);

    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }

    int da = furthest(1,-1, false).second;
    int db = furthest(da,-1, true).second;
    furthest(db,-1, true);

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << ' ';
    }

    return 0;
}