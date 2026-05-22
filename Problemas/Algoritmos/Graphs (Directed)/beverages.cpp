#include <bits/stdc++.h>
using namespace std;

int n, m;
map<string, int> code;
vector<string> str;
vector<set<int>> grafo;
vector<int> grau;

int main() {
    for (int t = 1; cin >> n && (n!=0); ++t) {
        grafo.clear();
        grafo.resize(n);
        str.clear();
        str.resize(n);
        grau.clear();
        grau.resize(n);

        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            code[s] = i;
            str[i] = s;
        }
        cin >> m;
        for (int i = 0; i < m; ++i) {
            string a, b;
            cin >> a >> b;
            grafo[code[a]].insert(code[b]);
            ++grau[code[a]];
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (grau[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int u : grafo[v]) {
                --grau[u];

            }
        }
    }

    return 0;
}