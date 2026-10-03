// https://cses.fi/problemset/task/1139
// Incompleto

#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
typedef pair<int,int> pii;

int n;
vector<int> c;
vector<set<int>> g;

int global = 0;
vector<int> tin, tout, id;

void euler(int u, int p) {
    tin[u] = global;

    for (int v : g[u]) {
        if (v==p) continue;
        global++;
        euler(v,u);
    }
    tout[u] = global;
}

vector<int> seg;

// SegTree não funciona
void build(int l, int r, int i, int sl, int sr) {
    if (sr < l || sl > r) return;
    if (sl == sr) {
        seg[i] = 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    c.resize(n+1);
    g.resize(n+1);
    tin.resize(n+1);
    tout.resize(n+1);
    id.resize(n);
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }

    euler(1,-1);

    vector<pii> tempv(n);
    for (int i = 1; i <= n; i++) {
        tempv[i-1] = {tin[i],i};
        debug("%d=%d,%d\n",i,tin[i],tout[i]);
    }

    sort(tempv.begin(),tempv.end());
    for (auto[ in, i ] : tempv) {
        debug("%d ", i);
        id[in] = i;
    } debug("\n");



    return 0;
}