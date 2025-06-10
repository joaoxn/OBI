//
// Created by xnaxg on 01/06/2025.
// Exercício: https://neps.academy/br/exercise/2322
// Resolvido em: 07m:00s
// Tempo total de prova (OBI 2023): 56m:32s
//

#include <iostream>
#include <vector>
using namespace std;

typedef struct {
    string nome;
    int valor;
} Lance;

int main() {
    int n;
    cin >> n;

    string ganhador;
    int max = 0;

    for (int i = 0; i < n; i++) {
        string c;
        int v;
        cin >> c >> v;

        if (v <= max)  continue;
        max = v;
        ganhador = c;
    }

    cout << ganhador << endl << max;
}
