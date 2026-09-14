// https://cses.fi/problemset/task/1682

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define IGN if (0) 
#define fi first
#define se second.first
#define th second.second
typedef pair<int,pair<int,int>> trio;
typedef long long ll;

int n, m;
vector<set<int>> g;
vector<int> id;
vector<int> low;
int global = 1;

vector<int> st;
vector<bool> inStack;
int amt = 0;
vector<int> roots;
void dfs(int u) {
    id[u] = global++;
    low[u] = id[u];
    st.push_back(u);
    inStack[u] = true;

    for (int v : g[u]) {
        if (id[v] == -1) {
            dfs(v);
            low[u] = min(low[u],low[v]);
        } else if (inStack[v]) {
            low[u] = min(low[u],id[v]);
        }
    }
    if (id[u] == low[u]) {
        while (st.back() != u) {
            inStack[st.back()] = false;
            st.pop_back();
        }
        inStack[u] = false;
        st.pop_back();
        roots.push_back(u);
        amt++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    g.resize(n+1);
    id.resize(n+1,-1);
    low.resize(n+1,INT_MAX);
    inStack.resize(n+1);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].insert(b);
    }

    for (int i = 1; i <= n; i++) {
        if (id[i] == -1) dfs(i);
    }

    if (amt == 1) cout << "YES";
    else {
        cout << "NO\n";
        int a = roots[0], b = roots[1];
        if (g[a].find(b) != g[a].end()) {
            swap(a,b);
        }
        cout << a << ' ' << b;
    }

    return 0;
}