/*
Conectar para Conquistar
Pontuação desse Envio: 100/100 (Todas as Subtarefas)
Pontuação da Questão: 100/100 (Todas as Subtarefas)
Pontuação da Prova: 232/500 (100+100+25+7)

Estratégia:
    Utilizar Union-Find para definir os conjuntos.
    Manter o menor de dois reinos de uma consulta isolado de todos os outros componentes.
    O grafo com o máximo de arestas será o fecho transitivo entre o grafo sem o conjunto isolado, 
    junto com o fecho transitivo desse conjunto isolado.
    A quantidade de arestas será a soma das quantidades de cada fecho menos a quantidade já existente.
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
#define int long long
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n, m, q;
vector<set<int>> g;
vector<int> gr;
vector<int> sz;
vector<int> dp;

void grs(int u) {

    for (int v : g[u]) {
        if (gr[v] != 0) continue;
        gr[v] = gr[u];
        sz[gr[u]]++;
        grs(v);
    }
}

int32_t main() {
    // comandos para agilizar entrada/saída
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> q;
    g.resize(n+1);
    gr.resize(n+1);
    sz.resize(n+1);
    dp.resize(n+1, -1);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }
    // TODO gerador de grupos ids
    vector<int> roots;
    for (int i = 1; i <= n; i++) {
        if (gr[i] == 0) {
            roots.push_back(i);
            gr[i] = i;
            sz[i] = 1;
            grs(i);
        }
    }
    
    ll preSol = 0;
    for (int u : roots) {
        ll calc = (sz[u]*(sz[u]-1))/2;
        preSol += calc;
    }
    preSol -= m;

    

    ll maxTotal = preSol;
    ll localSz = sz[roots[0]];
    debugln("max %lld, sz %lld", maxTotal, localSz);
    for (int u : roots) {
        if (u == roots[0]) continue;
        debugln("[%lld] sz=%lld, %lld: %lld", u, sz[u], localSz*sz[u], maxTotal);
        maxTotal += (localSz * sz[u]);
        localSz += sz[u];
    }

    debugln("%lld, sz %lld", maxTotal, localSz);

    while (q-- > 0) {
        int a, b; cin >> a >> b;
        a = gr[a];
        b = gr[b];
        if (gr[a] == gr[b]) {
            cout << "-1\n";
            continue;
        }
        if (sz[a] < sz[b]) swap(a,b);
        
        ll sol = maxTotal - sz[b]*(localSz-sz[b]);

        cout << sol << '\n';
    }

    return 0;
}