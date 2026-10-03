// https://judge.beecrowd.com/pt/problems/view/1790

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define IGN if (0) 
#define fi first
#define se second
#define sf second.first
#define th second.second
typedef pair<ll,pair<ll,ll>> trio;
typedef pair<ll,ll> pii;
typedef long long ll;

#define INF LLONG_MAX

int n, m;
vector<set<int>> g;
vector<int> id;
vector<int> low;
int t = 1;
int pontes = 0;

void outv(vector<int>& v) {
    for (int i = 1; i <= n; i++) cout << v[i] << ' ';
    cout << '\n';
}

void dfs(int u, int p=-1) {
    if (id[u] <= 0) {
        id[u] = t++;
        low[u] = id[u];
    }

    for (int v : g[u]) {
        if (v == p) continue;
        if (id[v] > 0) {
            low[u] = min(low[u], id[v]);
        } else {
            dfs(v,u);
            if (low[v] < low[u]) low[u] = low[v];
            if (low[v] > id[u]) pontes++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> n >> m) {
        g.clear(); g.resize(n+1);
        id.clear(); id.resize(n+1);
        low.clear(); low.resize(n+1);
        t = 1;
        pontes = 0;

        for (int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            g[a].insert(b);
            g[b].insert(a);
        }

        dfs(1);
        
        // outv(id);
        // outv(low);

        cout << pontes << '\n';
    }

    return 0;
}