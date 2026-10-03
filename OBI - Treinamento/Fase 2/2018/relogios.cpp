// !incompleto

#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)
#define fi first
#define se second
typedef pair<int,int> pii;

const int INF = INT_MAX >> 1;
int n, m, k;
vector<vector<int>> g;
vector<pii> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
vector<vector<int>> dist;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    g.resize(n,vector<int>(m));
    dist.resize(n,vector<int>(m, INF));
    dist[0][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }

    queue<pii> q;
    q.push({0,0});

    while (!q.empty()) {
        pii u = q.front(); q.pop();
        int c = g[u.fi][u.se];
        int d = dist[u.fi][u.se];

        for (pii dir : dirs) {
            int f = u.fi+dir.fi;
            int s = u.se+dir.se;

            if (g[f][s] == -1 || g[f][s] == c+1) dist[f][s] = dist[u.fi][u.se]+1;
            else if (c == -1) {
                dist[f][s] = d + g[f][s]-c;
            }
        }
    }

    return 0;
}