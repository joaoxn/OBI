// https://cses.fi/problemset/task/1671

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define IGN if (0) 
#define fi first
#define se second.first
#define th second.second
typedef pair<int,pair<int,int>> trio;
typedef pair<int,int> pii;
typedef long long ll;

int n, m;
vector<set<pii>> g;
vector<int> dist;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    g.resize(n+1);
    dist.resize(n+1);

    map<pii,int> mp;
    vector<pii> edges;

    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        pii k = {a,b};
        mp[k] = min(mp[k],c);
        edges.push_back(k);
    }
    for (pii edge : edges) g[edge.fi].insert({edge.second,mp[edge]});

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({1,0});
    while (!pq.empty()) {
        pii u = pq.top(); pq.pop();

        for (pii v : g[u.fi]) {

        }
    }

    return 0;
}