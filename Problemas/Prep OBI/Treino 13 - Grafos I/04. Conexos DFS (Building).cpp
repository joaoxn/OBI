#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)

int n, m;
vector<set<int>> g;
vector<int> isle;
vector<int> king;
int global = 0;

void dfs(int u) {
    for (int v : g[u]) {
        if (isle[v] != 0) continue;
        isle[v] = global;
        dfs(v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    g.resize(n+1);
    isle.resize(n+1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }

    for (int i = 1; i <= n; i++) {
        if (isle[i] != 0) continue; 
        global++;
        king.push_back(i);

        dfs(i);
    }

    cout << global-1 << '\n';
    for (int i = 0; i < global-1; i++) {
        cout << king[i] << ' ' << king[i+1] << '\n';
    }

    return 0;
}