/*
O Analista
Pontuação desse Envio: 17/100 (Subtarefas 2 e 3)
Pontuação da Questão: 25/100 (Subtarefas 2, 3 e 4)
Pontuação da Prova: 232/500 (100+100+25+7)

Estratégia:
    *Subtarefa 2: K = 0
    Quando K = 0, existe a solução gulosa de montar os intervalos da direita para a esquerda.
    O último intervalo será sempre os valores entre o maior valor da lista e o último elemento.
    Em casos de múltiplos maiores, será sempre o mais à direita.
    Com o último intervalo definido, é possível fazer o mesmo processo com os valores que ainda
    não tem um intervalo, ou seja, o subarray do início até o elemento anterior ao início do 
    último intervalo.
    Basta repetir isso até algum intervalo começar no início da lista.

    *Subtarefa 3: N <= 20
    Como N vai até 20, é possível fazer um Brute Force na escolha de quais elementos remover
    podendo remover até K elementos.
    Para cada elemento, é possível removê-lo (caso haja remoções disponíveis) ou não. 
    Se remover, terá menos remoções disponíveis para os outros elementos faltantes.

    Complexidade Temporal: O(2^min(N,K)) = O(2^N)
*/


// ========================
// Compilador online da OBI
// ========================

#include <bits/stdc++.h>
using namespace std;

#define debug(args...)
// #define debug(args...) fprintf(stderr, args)
#define debugln(args...) do { debug(args); debug("\n"); } while (0)
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n, k;
vector<int> v;
vector<int> pai;
vector<int> sz;

int sol() {
    int inicial = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] != -1) {
            inicial = i;
            break;
        }
    }

    int maxi = n;
    int total = 0;
    while (maxi != inicial) {
        int maxv = 0;
        int curri = 0;
        for (int i = 0; i < maxi; i++) {
            if (v[i] == -1) continue;
            debugln("i %d, vi %d, maxv %d", i, v[i], maxv);
            if (v[i] > maxv) {
                maxv = v[i];
                curri = i;
            }
        }
        maxi = curri;
        debugln("mx[%d]:%d", maxi, maxv);
        total++;
    }

    return total;
}

int backtrack(int k, int last) {
    if (last == n-1) return 0;
    if (k == 0) return sol();

    int maxv = 0;
    for (int i = last+1; i < n; i++) {
        int temp = v[i];
        v[i] = -1;
        int x = backtrack(k-1, i);
        v[i] = temp;
        maxv = max(maxv, x);
    }
    return maxv;
}

int main() {
    // comandos para agilizar entrada/saída
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    v.resize(n);
    pai.resize(n);
    sz.resize(n, 1);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        pai[i] = i;
    }

    // int currPai = 0;
    // for (int i = 1; i < n; i++) {
    //     if (v[i-1] < v[i]) {
    //         pai[i] = currPai;
    //         sz[pai[i]]++;
    //     } else {
    //         currPai = i;
    //     }
    // }
    // vector<int> roots;
    // for (int i = 0; i < n; i++) {
    //     if (pai[i] == i) {
    //         roots.push_back(i);
    //         debugln("i:%d, v:%d, sz:%d", i, v[i], sz[i]);
    //     }
    // }

    
    // for (int r : roots) {
    //     int u = r-1;
    //     int lastgood = -1;
    //     for (int i = pai[u]; i < u; i++) { // Can Binary Search
    //         if (v[i] >= v[r]) {
    //             lastgood = i-1;
    //             break;
    //         }
    //     }
    //     int cost = u-lastgood;
    //     int gain = sz[u]-cost + sz[r];
    // }

    int maxv = 0;
    for (int i = 0; i <= k; i++) {
        maxv = max(maxv, backtrack(i,-1));
    }
    cout << maxv;
    return 0;
}