// ========================
// Compilador online da OBI
// ========================

#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)
#define debugln(args...) printf(args); printf("\n")
typedef long long ll;

int main() {
    // comandos para agilizar entrada/saída
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, p;
    cin >> a >> b >> p;
    int da = abs(a-p);
    int db = abs(b-p);

    if (da < db) cout << 'A';
    else if (da > db) cout << 'B';
    else cout << 'E';

    return 0;
}