// https://neps.academy/br/exercise/264

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define IGN if (0) 
#define fi first
#define se second

int n, k;
vector<int> pai;
vector<int> sz;

int find(int a, int ha=-1) {
    int v = a;
    while (pai[v] != v) {
        int next = pai[v];
        if (ha != -1) pai[v] = ha;
        v = next;
    }
    if (ha == -1) find(a,v);
    return v;
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

    cin >> n >> k;
    pai.resize(n+1);
    sz.resize(n+1, 1);
    for (int i = 1; i <= n; i++) pai[i] = i;

    for (int i = 0; i < k; i++) {
        char t; cin >> t;
        int a, b; cin >> a >> b;
        int ha = find(a), hb = find(b);

        if (t == 'C') {
            cout << (ha == hb ? 'S' : 'N') << '\n';
        } else  if (ha != hb) {
            unite(ha,hb);
        }
    }

    return 0;
}