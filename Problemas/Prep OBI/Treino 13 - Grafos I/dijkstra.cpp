#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> pl3;
const int INF = INT_MAX >> 1;
const ll LINF = LLONG_MAX >> 2;

int n, m;
vector<set<pll>> g;
vector<ll> dist;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    g.resize(n+1);
    dist.resize(n+1, LINF);

    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        g[a].insert({b,c});
    }

    priority_queue<pll,vector<pll>,greater<pll>> pq;
    pq.push({0,1});
    dist[1] = 0;

    while (!pq.empty()) {
        auto [d,u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;

        for (auto [v,c] : g[u]) {
            ll newd = dist[u]+c;
            if (newd < dist[v]) {
                dist[v] = newd;
                pq.push({dist[v],v});
            }
        }
    }

    for (int i = 1; i <= n; i++) cout << dist[i] << ' ';

    return 0;
}