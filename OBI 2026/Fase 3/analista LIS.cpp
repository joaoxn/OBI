/*
O Analista
Pontuação desse Envio: 8/100 (Subtarefa 4)
Pontuação da Questão: 25/100 (Subtarefas 2, 3 e 4)
Pontuação da Prova: 232/500 (100+100+25+7)

Estratégia:
    *Subtarefa 4: K = N
    Quando K = N, podemos escolher remover quaisquer elementos, sem restrições. 
    Assim, o problema passa ser exatamente o LIS (Longest Increasing Subsequence), 
    onde a maior subsequência crescente terá o maior número de elementos possível, 
    os elementos não pertencentes à LIS serão removidos e os intervalos serão de 
    tamanho 1, cada um contendo um elemento da LIS.

    Na prática, não temos que nos preocupar com a remoção dos elementos nem com os 
    intervalos, pois a questão pede apenas o tamanho. Assim, essa subtarefa se 
    traduz exatamente para o LIS.

    Nesse código, implementei o LIS com retorno o tamanho da subsequência.
    O código abaixo foi escrito inteiramente durante a prova, sem alterações.
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

int n, k;
vector<int> v;
vector<int> dp;

int main() {
    // comandos para agilizar entrada/saída
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    v.resize(n);
    dp.resize(n, 1);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (v[j] >= v[i]) continue;
            dp[i] = max(dp[i], dp[j]+1);
        }
    }

    int maxv = 0;
    for (int i = 0; i < n; i++) {
        maxv = max(maxv, dp[i]);
    }

    cout << maxv;

    return 0;
}