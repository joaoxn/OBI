// https://cses.fi/problemset/task/1682

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define IGN if (0) 
#define fi first
#define se second.first
#define th second.second
typedef pair<int,pair<int,int>> trio;
typedef long long ll;

int n, m;
vector<int> pai;
vector<int> sz;
priority_queue<trio, vector<trio>, greater<trio>> pq;

int find(int a) {
    if (pai[a] == a) return a;
    return pai[a] = find(pai[a]);
}

void unite(int a, int b) {
    int ha = find(a), hb = find(b);
    if (sz[ha] < sz[hb]) swap(ha,hb);
    
    pai[hb] = ha;
    sz[ha] += sz[hb];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    pai.resize(n+1);
    sz.resize(n+1, 1);
    for (int i = 1; i <= n; i++) pai[i] = i;

    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        pq.push({c, {a,b}});
    }

    ll cost = 0;
    int isles = n;
    while (!pq.empty()) {
        trio r = pq.top(); pq.pop();
        int ha = find(r.se), hb = find(r.th);
        if (ha == hb) continue;
        unite(ha,hb);
        isles--;
        cost += r.fi;
    }

    if (isles == 1) cout << cost;
    else cout << "IMPOSSIBLE";

    return 0;
}