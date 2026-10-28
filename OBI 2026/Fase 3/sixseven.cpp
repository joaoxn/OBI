/*
Six-Seven
Pontuação desse Envio: 100/100 (Todas as Subtarefas)
Pontuação da Questão: 100/100 (Todas as Subtarefas)
Pontuação da Prova: 232/500 (100+100+25+7)
*/

// ========================
// Compilador online da OBI
// ========================

#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr, args)
#define debugln(args...) do { debug(args); debug("\n"); } while (0)
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll n;

int main() {
    // comandos para agilizar entrada/saída
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    ll d = n/6;
    ll y = 0;

    while (d >= 0 && 6*d+7*y != n) {
        y++; d--;
        if (6*d + 7*y == n) break;
    }

    if (d < 0) {
        cout << -1;
    } else {
        cout << d << ' ' << y;
    }

    return 0;
}