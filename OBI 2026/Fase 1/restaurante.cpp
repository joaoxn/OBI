// ========================
// Compilador online da OBI
// ========================

#include <bits/stdc++.h>
using namespace std;

int g1, g2, g3, g4;

int main() {
    // comandos para agilizar entrada/saída
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> g1 >> g2 >> g3 >> g4;

    int total = g4;
    int min1e3 = min(g1,g3);
    total += min1e3;
    g1 -= min1e3;
    g3 -= min1e3;

    total += g3;
    
    total += g2/2;
    if (g2%2 == 1) {
        total++;
        g1 -= 2;
    }

    total += g1/4;
    if (g1%4 > 0) total++;

    cout << total;

    return 0;
}