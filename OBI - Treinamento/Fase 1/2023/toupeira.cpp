//
// Created by xnaxg on 01/06/2025.
// Exercício: https://neps.academy/br/exercise/2323
// Resolvido em: 29m:56s
// Tempo total de prova (OBI 2023): 56m:32s
//

#include <iostream>
#include <map>
#include <vector>
using namespace std;


int main() {
    int s, t;
    cin >> s >> t;

    // map<int, map<int, bool>> mapa{};
    bool mapa[s+1][s+1] = {};


    for (int i = 0; i < t; i++) {
        int x, y;
        cin >> x >> y;
        mapa[x][y] = true;
        mapa[y][x] = true;
    }

    int p;
    cin >> p;
    int count = 0;
    for (int i = 0; i < p; i++) {
        int n;
        cin >> n;

        int prev;
        cin >> prev;

        bool possible = true;
        for (int j = 1; j < n; j++) {
            int c;
            cin >> c;
            if (!mapa[prev][c]) {
                possible = false;
            }
            prev = c;
        }
        if (possible) count++;
    }

    cout << count;

    return 0;
}
