// https://neps.academy/br/exercise/3580
// 100/100

#include <bits/stdc++.h>
using namespace std;

#define IGN if (0) 
#define fi first
#define se second.first
#define th second.second
typedef pair<int,pair<int,int>> pii;
typedef long long ll;

int n, m, k;
vector<set<int>> g;
queue<pii> rodos;
vector<int> pai;
vector<int> sz;

int find(int x) {
    if (pai[x] == x) return x;
    return pai[x] = find(pai[x]);
}

void unite(int a, int b) {
    int ha = find(a), hb = find(b);
    if (ha == hb) return;
    if (sz[ha] < sz[hb]) {
        pai[ha] = hb;
        sz[hb] += sz[ha];
    } else {
        pai[hb] = ha;
        sz[ha] += hb;
    }
}

vector<bool> vis;
bool cycle(int u, int c = -1) {
    if (vis[u]) return true;
    vis[u] = true;
    for (int v : g[u]) {
        if (v == c) continue;
        if (cycle(v, u)) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    g.resize(n+1);
    pai.resize(n+1);
    sz.resize(n+1);
    vis.resize(n+1);

    for (int i = 1; i <= n; i++) pai[i] = i;

    for (int i = 0; i < m; i++) {
        int a, b, t; cin >> a >> b >> t;
        if (t == 1) {
            g[a].insert(b);
            g[b].insert(a);
            unite(a,b);
        } else {
            rodos.push({a,{b,0}});
        }
    }

    int useless = 0;
    while (!rodos.empty()) {
        pii u = rodos.front(); rodos.pop();
        int ha = find(u.fi), hb = find(u.se);
        if (ha == hb) {
            useless++;
            IGN printf("Trash (%d, %d) [%d]\n", u.fi, u.se, ha);
            continue;
        }
        
        g[u.fi].insert(u.se);
        g[u.se].insert(u.fi);
        unite(ha, hb);
    }

    char sol = 'S';
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        if (cycle(i)) {
            sol = 'N';
            break;
        }
    }

    if (useless > k) sol = 'N'; 

    cout << sol;
IGN    cout << '\n' << useless;
}
