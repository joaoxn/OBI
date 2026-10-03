#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)

int n, m;
vector<set<int>> g;
vector<int> team;

bool dfs(int u, bool first) {
    team[u] = first;

    for (int v : g[u]) {
        if (team[v] == first) return false;
        if (team[v] != -1) continue;

        if (!dfs(v,!first)) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    g.resize(n+1);
    team.resize(n+1,-1);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }

    bool success = true;
    for (int i = 1; i <= n; i++) {
        if (team[i] != -1) continue;
        if (!dfs(i,0)) {
            success = false;
            break;
        }
    }

    if (!success) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (int i = 1; i <= n; i++) {
            cout << (team[i]+1) << ' ';
        }
    }

    return 0;
}