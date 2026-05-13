#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<set<int>> grafo;

int color[101];

bool dfs(int v, int c) {
    if (color[v] != -1 && color[v] != c) 
        return false;
    if (color[v] == c) 
        return true; // skip v
    
    color[v] = c;
    for (int next : grafo[v]) {
        bool res = dfs(next, (c+1)%2);
        if (!res) 
            return false;
    }
    return true;
}

int main() {
    for (int t = 1; scanf("%d %d", &n, &m) > 0 && (n!=0 || m!=0); ++t) {
        grafo.clear();
        grafo.resize(n+1);
        
        for (int i = 0; i < m; ++i) {
            int a, b;
            scanf("%d %d", &a, &b);
            grafo[a].insert(b);
            grafo[b].insert(a);
        }
        bool ans = true;

        for (int i = 1; i <= n; ++i) {
            color[i] = -1;
        }

        for (int v = 1; v <= n; ++v) {
            if (color[v] != -1) continue;
            bool res = dfs(v,0);
            if (!res) {
                ans = false;
                break;
            }
        }
        
        printf("Instancia %d\n", t);
        printf(ans ? "sim\n\n" : "nao\n\n");
    }

    return 0;
}