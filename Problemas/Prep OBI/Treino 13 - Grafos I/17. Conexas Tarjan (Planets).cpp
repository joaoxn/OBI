// https://cses.fi/problemset/task/1683/

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<set<int>> g;
vector<int> id;
vector<int> low;
int idg = 1;
stack<int> st;
vector<int> comp;
int comps = 0;
vector<bool> in_stack;

void dfs(int u) {
    id[u] = idg++;
    low[u] = id[u];
    st.push(u);
    in_stack[u] = true;

    for (int v : g[u]) {
        if (id[v] == 0) {
            dfs(v);
            if (low[v] < low[u]) low[u] = low[v];
        } else if (in_stack[v]) {
            if (low[v] < low[u]) low[u] = low[v];
        }
    }
    if (low[u] != id[u]) return;
    comps++;
    while (st.top() != u) {
        comp[st.top()] = comps;
        in_stack[st.top()] = false;
        st.pop();
    }
    comp[u] = comps;
    in_stack[st.top()] = false;
    st.pop();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    g.resize(n+1);
    id.resize(n+1);
    low.resize(n+1);
    comp.resize(n+1);
    in_stack.resize(n+1);
    
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].insert(b);
    }

    for (int i = 1; i <= n; i++) {
        if (id[i] == 0) dfs(i);
    }

    cout << comps << '\n';
    for (int i = 1; i <= n; i++) cout << comp[i] << ' ';
}