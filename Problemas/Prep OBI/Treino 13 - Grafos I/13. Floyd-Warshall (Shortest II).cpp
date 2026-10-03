#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)
typedef long long ll;
const ll INF = LLONG_MAX >> 2;

int n, m, q;
vector<vector<ll>> d;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> q;
    d.resize(n+1,vector<ll>(n+1, INF));
    for (int i = 1; i <= n; i++) 
        d[i][i] = 0;

    for (int i = 0; i < m; i++) {
        ll a, b, c; cin >> a >> b >> c;
        d[a][b] = min(d[a][b],c);
        d[b][a] = min(d[b][a],c);
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
            }

    while (q-- > 0) {
        int a, b; cin >> a >> b;
        if (d[a][b] == INF) cout << -1;
        else cout << d[a][b];
        cout << '\n';
    }

    return 0;
}