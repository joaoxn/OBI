#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)

int n;
vector<int> sub;
vector<set<int>> g;

int dfs(int u) {
    int sum = 0;
    for (int v : g[u]) {
        sum += dfs(v)+1;
    }
    sub[u] = sum;
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    sub.resize(n+1);
    g.resize(n+1);
    for (int i = 2; i <= n; i++) {
        int pai; cin >> pai;
        g[pai].insert(i);
    }

    dfs(1);

    for (int i = 1; i <= n; i++) {
        cout << sub[i] << ' ';
    }

    return 0;
}