// https://atcoder.jp/contests/dp/tasks/dp_g?lang=en

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<set<int>> g;
vector<int> dp;

int dfs(int u) {
    if (dp[u] != -1) return dp[u];
    int maxd = 0;
    int best = -1;
    for (int v : g[u]) {
        int last = maxd;
        maxd = max(maxd,dfs(v)+1);
        if (last != maxd) best = v;
    }
    dp[u] = maxd;
    // cout << u << ": ";
    // for (int i = 1; i <= n; i++) {
    //     cout << dp[i] << ' ';
    // } cout << "["<< best <<"]" << '\n';

    return maxd;
}

int main() {
    cin >> n >> m;
    g.resize(n+1);
    dp.resize(n+1,-1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].insert(b);
    }

    int maxv = 0;
    for (int i = 1; i <= n; i++) {
        maxv = max(maxv, dfs(i));
        
    }

    cout << maxv << '\n';
}