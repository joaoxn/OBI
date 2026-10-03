#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)

int n, m;
vector<set<int>> g;
vector<int> team;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    g.resize(n+1);
    team.resize(n+1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }

    bool possible = true;
    for (int i = 1; i <= n; i++) {
        if (team[i] != 0) continue;
        team[i] = 1;

        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            int t = !(team[u]-1)+1;

            for (int v : g[u]) {
                if (team[v] != 0 && team[v] != t) {
                    possible = false;
                    break;
                } else if (team[v] != 0) continue;
                team[v] = t;
                q.push(v);
            }
        }
    }
    if (!possible) cout << "IMPOSSIBLE";
    else {
        for (int i = 1; i <= n; i++) {
            cout << team[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
