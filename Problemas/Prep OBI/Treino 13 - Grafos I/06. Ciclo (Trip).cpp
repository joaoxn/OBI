#include <bits/stdc++.h>
using namespace std;

#define IGN if (0) 

int n, m;
vector<set<int>> g;
vector<int> path;
int psz = 0;
vector<int> vis; // 0 = no; 1 = in path; 2 = yes

void push(int x) {
    path[psz++] = x;
}

void pop() {
    --psz;
}

int dfs(int u, int c) {
    if (vis[u] == 1) {
        int pos = -1;
        for (int i = 0; i < psz-1; i++) {
            if (path[i] == u) {
                pos = i;
                break;
            }
        }
        return pos;
    }
    vis[u] = 1;
    
    for (int v : g[u]) {
        if (v == c) continue;
        push(v);

        IGN for (int i = 0; i < psz; i++) cout << path[i] << ' ';
        IGN cout << '\n';

        int pos = dfs(v, u);
        if (pos != -1) return pos;
        vis[v] = 2;
        pop();
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    g.resize(n+1);
    vis.resize(n+1);
    path.resize(n+2);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i] == 2 || g[i].size() < 2) continue;
        push(i);
        int pos = dfs(i,0);
        
        if (pos != -1) {
            cout << psz-pos << '\n';
            for (int j = pos; j < psz; j++) cout << path[j] << ' ';
            IGN cout << '\n' << pos;
            return 0;
        }

        for (int j = 0; j < psz; j++) vis[path[i]] = 2;
        psz = 0;
    }
    cout << "IMPOSSIBLE";

    return 0;
}