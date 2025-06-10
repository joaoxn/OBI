//
// Created by xnaxg on 01/06/2025.
// Exercício: https://neps.academy/br/exercise/2319
// Resolvido em: 08m:43s
// Tempo total de prova (OBI 2023): 56m:32s
//

#include <iostream>
#include <vector>
using namespace std;


int main() {
    int m, n;
    cin >> m >> n;

    vector matrix(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            matrix[i][j] = x;
        }
    }

    int p;
    cin >> p;

    int vendidos = 0;
    for (int it = 0; it < p; it++) {
        int i, j;
        cin >> i >> j;
        i--;
        j--;

        if (matrix[i][j] == 0) continue;
        vendidos++;
        matrix[i][j]--;
    }

    cout << vendidos;
}
