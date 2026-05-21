// Algoritmo não resolve todos os casos.
// TODO: pensar em novo algoritmo

#include <bits/stdc++.h>
using namespace std;

int t, v, e;
vector<set<int>> grafo;
int cores[201];

bool ehBipartido(int n, int cor) {
    cores[n] = cor;
    for (int u : grafo[n]) {
        // printf("cores[%d,%d]=%d,%d\n", n,u,cores[n],cores[u]);
        if (cores[u] != -1 && cores[u] == cores[n])
        return false;
        if (cores[u] != -1) continue;
        if (!ehBipartido(u, (cor+1)%2))
            return false;
    }
    return true;
}

int main() {
    scanf("%d", &t);
    for (int _t = 0; _t < t; ++_t) {
        scanf("%d %d", &v, &e);
        
        grafo.clear();
        grafo.resize(v+1);
        memset(cores, -1, sizeof cores);

        for (int i = 0; i < e; ++i) {
            int f, t;
            scanf("%d %d", &f, &t);
            grafo[f].insert(t);
            grafo[t].insert(f);
        }
        int total = 0;
        int lastTotalIt = 0;
        for (int i = 0; i < v; ++i) {
            if (cores[i] != -1) continue;
            if (!ehBipartido(i, 0)) goto fail;
            int totalIt = 0;
            for (int j = 0; j < v; ++j) 
            if (cores[j] != -1) ++totalIt;

            int tamSub = totalIt - lastTotalIt;
            if (tamSub > 3 && tamSub % 3 == 1) goto fail;
            total += max(1.0,ceil(tamSub/3.0));
            
            lastTotalIt = totalIt;
        }
        printf("%d\n", total);
        continue;
        
        fail:
        printf("-1\n");
    }
        
    return 0;
}

/* Grafos Bipartidos
1. Verificar se é bipartido.
- Se não for, print(-1)
2. Contar os guardas: *Não Funciona!

- Se vi%3==1 e vi > 3, não é possível
- Guloso: sum(vi/3) para todo vi, onde vi é um subgrafo conexo
- Para vi <= 3, somar 1
- Gera a quandidade de guardas
*/