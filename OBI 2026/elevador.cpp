// ========================
// Compilador online da OBI
// ========================

#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    // comandos para agilizar entrada/saída
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    int last; cin >> last;
    int total = 0;
    for (int i = 1; i < n; i++) {
        int curr; cin >> curr;
        total += abs(last-curr);
        last = curr;
    }

    cout << total;

    return 0;
}
