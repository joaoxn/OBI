/*
Subtarefa 1 e 2 (40/100): Força Bruta
Iterar todos os valores de 1 até N, e contar todos que não são divisíveis por K.

Subtarefa 1 e 2 (40/100): Crivo de Erastótenes
Mesma pontuação, porém mais eficiente para maiores valores de K.

Subtarefa 3 (80/100): Cálculo de múltiplos dos primos
Para cada primo, calcular quantos múltiplos ele tem até N;
Para evitar contagens repetidas, considerar múltiplos de dois ou mais primos;
Total de somas: 2^k; É aprovado para K <= 20.

Subtarefa 4 (100/100): Não sei

*/

#include <bits/stdc++.h>
using namespace std;

int n, k;
int primo[40];

int main() {
    scanf("%d %d", &n, &k);
    int mmc = 1;
    for (int i = 0; i < k; ++i) {
        scanf("%d", primo+i);
        mmc *= primo[i];
    }
    
    bool crivo[mmc+1];
    memset(crivo, false, sizeof crivo);
    
    int coprimos = mmc;
    int resto_coprimos = n%mmc;
    for (int i = 0; i < k; ++i) {
        int p = primo[i];

        for (int j = p; j <= mmc; j += p) {
            if (crivo[j] == true) continue;
            crivo[j] = true;
            
            --coprimos;
            if (j <= n%mmc) --resto_coprimos;
        }
    }

    int total = coprimos * (n/mmc) + resto_coprimos;
    printf("%d\n", total);

    return 0;
}
/*
10 - 10/2 - 10/3 + 10/(2*3)
10 - 5 - 3 + 1
3

20 - 20/2 - 20/5 - 20/7 + 20/(2*5) + 20/(2*7) + 20/(5*7) + 20/(2*5*7)
20 - 10 - 4 - 2 + 2 + 1 + 0 + 0
4 + 3
7

30 - 30/2 - 30/3 - 30/5 + 30/(2*3) + 30/(2*5) + 30/(3*5) - 30/(2*3*5)
30 - 15 - 10 - 6 + 5 + 3 + 2 - 1
-1 + 10 - 1
8

2 4 6 8 10 12 14 16 18 20 22 24 26 28 30
.3  6  9   12   15  18   21  24   27  30
.  5    10      15     20      25     30

30/2 - 30/3 - 30/5 + 30/(2*3) + 30/(3*5) - 30/(2*3*5)




*/