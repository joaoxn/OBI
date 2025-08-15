//
// Created by xnaxg on 01/06/2025.
// Exercício: https://neps.academy/br/exercise/2321
// Resolvido em: 08m:33s
// Tempo total de prova (OBI 2023): 56m:32s
//

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int v;
    vector<int> contas(3);
    cin >> v >> contas[0] >> contas[1] >> contas[2];

    sort(contas.begin(), contas.end());

    int pagas = 0;
    for (int conta : contas) {
        v -= conta;
        if (v < 0) continue;
        pagas++;
    }

    cout << pagas;
}
