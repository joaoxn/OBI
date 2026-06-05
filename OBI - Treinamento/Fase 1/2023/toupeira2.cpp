#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)

int s, t, p;
vector<set<int>> grafo;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> s >> t;
    grafo.resize(s+1);

    for (int i = 0; i < t; i++) {
        int x, y; cin >> x >> y;
        grafo[x].insert(y);
        grafo[y].insert(x);
    }
    cin >> p;
    int total = 0;
    for (int i = 0; i < p; i++) {
        int n; cin >> n;
        bool possivel = true;
        int curr; cin >> curr;
        for (int j = 1; j < n; j++) {
            int c; cin >> c;
            if (grafo[curr].find(c) == grafo[curr].end()) possivel = false;
            curr = c;
        }
        total += possivel;
    }
    cout << total;

    return 0;
}