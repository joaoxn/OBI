// https://judge.beecrowd.com/pt/problems/view/3044

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<set<int>> g;
vector<int> id;
vector<int> low;
int idg;
set<int> arts;

void dfs(int u, int p=-1) {
    id[u] = idg++;
    low[u] = id[u];

    for (int v : g[u]) {
        if (v == p) continue;
        if (id[v] == 0) {
            dfs(v,u);
            if (u != 1 && low[v] >= id[u]) { // Articulation
                arts.insert(u);
            }
            low[u] = min(low[u], low[v]);
        } else {
            low[u] = min(low[u], id[v]);
        }
    }
    if (u != 1) return;
    // Verifica se 1 é Articulação
    int lowg = -1;
    for (int v : g[u]) {
        if (lowg != -1 && lowg != low[v]) {
            arts.insert(u);
            break;
        }
        lowg = low[v];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m; 
    for (int T = 1; n != 0; T++) {
        g.clear(); g.resize(n+1);
        id.clear(); id.resize(n+1);
        low.clear(); low.resize(n+1);
        arts.clear();
        idg = 1;
        
        for (int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            g[a].insert(b);
            g[b].insert(a);
        }

        dfs(1);

        cout << "Teste " << T << '\n';
        if (arts.empty()) cout << "nenhum";
        else for (int x : arts) cout << x << ' ';
        cout << "\n\n";

        cin >> n >> m;
    }
}