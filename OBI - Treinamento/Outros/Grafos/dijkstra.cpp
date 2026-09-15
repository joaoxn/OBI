// https://neps.academy/br/exercise/297

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int n, m;
vector<vector<pii>> g;
vector<int> d;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    g.resize(n+2);
    d.resize(n+2, INT_MAX);
    d[0] = 0;
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0,0});
    while (!pq.empty()) {
        auto [dist, u] = pq.top(); pq.pop();
        if (dist > d[u]) continue;

        for (auto [v,c] : g[u]) {
            if (dist+c >= d[v]) continue;
            d[v] = dist+c;
            pq.push({d[v],v});
        }
    }
    
    cout << d[n+1];
}