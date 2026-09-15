// https://cses.fi/problemset/task/1671

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
vector<set<pii>> g;
vector<ll> d;
vector<bool> vis;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    g.resize(n+1);
    d.resize(n+1, INF);
    vis.resize(n+1);
    d[1] = 0;

    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        g[a].insert({b,c});
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({d[1], 1});
    while (!pq.empty()) {
        auto [dist, u] = pq.top(); pq.pop();
        if (dist > d[u]) continue;

        for (auto [v, c] : g[u]) {
            if (d[u]+c < d[v]) {
                d[v] = d[u]+c;
                pq.push({d[v],v});
            }
        }
    }

    for (int i = 1; i <= n; i++) cout << d[i] << ' ';

    return 0;
}