#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)

int n;
vector<set<int>> g;
vector<vector<int>> memo;

int dfs(int u, int p, bool used) {
    if (memo[u][used]) return memo[u][used];
    int sum = 0;
    int bestDiff = 0;
    for (int v : g[u]) {
        if (v == p) continue;
        
        int noTake = dfs(v,u,false);
        sum += noTake;
        int diff = dfs(v,u,true)+1 - noTake;
        if (diff > bestDiff) bestDiff = diff;
        
    }
    if (!used) sum += bestDiff;
    memo[u][used] = sum;
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    g.resize(n+1);
    memo.resize(n+1,vector<int>(2));

    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }
    
    cout << dfs(1,-1,false);

    return 0;
}