#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)

int n, m;
vector<set<int>> g; // Grafo
vector<int> t;      // Identificador, tempo de visita
vector<int> low;    // Menor id encontrado entre vizinhos
int glob = 0;       // Contador/Gerador de IDs

stack<int> st;      // Stack de nós no caminho atual
vector<bool> in_st; // Flag, true se nó i está na stack

vector<int> group;  // Identificador do componente de i
int ct = 0;         // Gerador de identificadores dos componentes

void dfs(int u) {
    t[u] = ++glob; 
    low[u] = t[u];
    st.push(u);
    in_st[u] = true;

    for (int v : g[u]) {
        if (t[v] == 0) {
            dfs(v);
            low[u] = min(low[u],low[v]);
        } else if (in_st[v]) {
            low[u] = min(low[u], t[v]);
        }
    }

    if (low[u] == t[u]) {
        ct++;
        while (st.top() != u) {
            int v = st.top(); st.pop();
            in_st[v] = false;
            group[v] = ct;
        }
        st.pop();
        in_st[u] = false;
        group[u] = ct;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    g.resize(n+1);
    t.resize(n+1);
    low.resize(n+1);
    in_st.resize(n+1);
    group.resize(n+1);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].insert(b);
    }

    for (int i = 1; i <= n; i++) {
        if (t[i] == 0) dfs(i);
    }

    cout << ct << '\n';
    for (int i = 1; i <= n; i++) cout << group[i] << ' ';

    return 0;
}