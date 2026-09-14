// https://cses.fi/problemset/task/1676

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define IGN if (0) 
#define fi first
#define se second

int n, m;
vector<int> pai;
vector<int> sz;

int find(int a) {
    if (pai[a] == a) return a;
    return pai[a] = find(pai[a]);
}

void unite(int a, int b) {
    int ha = find(a), hb = find(b);
    if (
        sz[ha] < sz[hb] || 
        sz[ha] == sz[hb] && hb <= ha
    ) {
        pai[ha] = hb;
        sz[hb] += sz[ha];
    } else {
        pai[hb] = ha;
        sz[ha] += sz[hb];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    pai.resize(n+1);
    sz.resize(n+1, 1);
    for (int i = 1; i <= n; i++) pai[i] = i;

    int components = n;
    int maxsz = 1;

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        int ha = find(a), hb = find(b);
        if (ha != hb) {
            unite(a,b);
            components--;
        }
        if (sz[ha] > maxsz) maxsz = sz[ha];
        if (sz[hb] > maxsz) maxsz = sz[hb];

        cout << components << ' ' << maxsz << '\n';
    }

    return 0;
}