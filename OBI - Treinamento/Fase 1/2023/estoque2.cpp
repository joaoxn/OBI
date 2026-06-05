#include <bits/stdc++.h>
using namespace std;

int n, m, p;
int a[501][501];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    cin >> p;
    int vendas = 0;
    for (int k = 0; k < p; k++) {
        int i, j; cin >> i >> j;
        if (a[i][j] <= 0) continue;
        a[i][j]--;
        vendas++;
    }
    cout << vendas;

    return 0;
}