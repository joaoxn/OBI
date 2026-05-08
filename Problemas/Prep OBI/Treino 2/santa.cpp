//
// Created by xnaxg on 07/04/2026.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string nomes[n];
    int bons = 0, ruins = 0;
    for (int i = 0; i < n; i++) {
        char comportamento;
        cin >> comportamento >> nomes[i];
        if (comportamento == '+') bons++;
        else ruins++;
    }
    sort(nomes, nomes+n);
    for (string s : nomes) cout << s << "\n";
    printf("Se comportaram: %d | Nao se comportaram: %d\n",bons,ruins);
}