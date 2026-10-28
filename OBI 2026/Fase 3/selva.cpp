/*
Selva
Pontuação desse Envio: 7/100 (Subtarefa 2)
Pontuação da Questão: 7/100 (Subtarefa 2)
Pontuação da Prova: 232/500 (100+100+25+7)

Estratégia:
    *Subtarefa 2: M = 1
    Como existe apenas um ponto a ser evitado, a solução será gulosamente tentar passar
    por alguma borda do mapa. Ou passará pelas laterais esquerda e superior, ou pelas
    laterais inferior e direita. O resultado é o máximo entre ambos.
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

const int INF = INT_MAX >> 1;
int n, m;
vector<vector<int>> g;
vector<pii> p;

int main() {
    // comandos para agilizar entrada/saída
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    
    int x, y; cin >> x >> y;
    int dist = max(min((n-1)-y, x), min((n-1)-x,y));

    cout << dist;

    return 0;
}