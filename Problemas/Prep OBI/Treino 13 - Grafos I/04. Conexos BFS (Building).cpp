#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)

int n, m;
vector<set<int>> g;
vector<int> isle;
vector<int> king;
int global = 0;

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

        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int u = q.front(); q.pop();

            for (int v : g[u]) {
                if (isle[v] != 0) continue;
                isle[v] = global;
                q.push(v);
            }
        }
    }

    cout << global-1 << '\n';
    for (int i = 0; i < global-1; i++) {
        cout << king[i] << ' ' << king[i+1] << '\n';
    }

    return 0;
}