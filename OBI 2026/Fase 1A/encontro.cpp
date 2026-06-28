// ========================
// Compilador online da OBI
// ========================

#include <bits/stdc++.h>
using namespace std;

int i1, f1, i2, f2, i3, f3;

int main() {
    // comandos para agilizar entrada/saída
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> i1 >> f1 >> i2 >> f2 >> i3 >> f3;

    int i = max({i1,i2,i3});
    int j = min({f1,f2,f3});

    cout << max(0,j-i+1);

    return 0;
}