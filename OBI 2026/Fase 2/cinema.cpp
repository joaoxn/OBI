// ========================
// Compilador online da OBI
// ========================

#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)
#define debugln(args...) printf(args); printf("\n")
typedef long long ll;

int n, m, c;
vector<int> hs;
vector<int> cap;
int sess = -1;

int main() {
    // comandos para agilizar entrada/saída
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> c;
    int clientes[n];
    hs.resize(m);
    cap.resize(m);
    for (int i = 0; i < n; i++) cin >> clientes[i];
    for (int i = 0; i < m; i++) cin >> hs[i];

    for (int t : clientes) {
        while (sess < m) {
            if (t <= hs[sess] && cap[sess] < c) {
                cap[sess]++;
                break;
            }
            else sess++;
        }
    }

    for (int i = 0; i < m; i++) cout << cap[i] << ' ';

    return 0;
}