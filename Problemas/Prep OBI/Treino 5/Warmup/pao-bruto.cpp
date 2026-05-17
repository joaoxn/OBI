#include <bits/stdc++.h>
using namespace std;

int n, k;
int maxBread = 1;
int pao[10001];

int calc(int tamanho) {
    int fatias = 0;
    for (int i = 0; i < k; ++i) {
        fatias += pao[i]/tamanho;
    }
    return fatias;
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &pao[i]);
        if (pao[i] > maxBread) maxBread = pao[i];
    }

    int i;
    for (i = maxBread; i >= 1; --i) {
        int pessoas = calc(i);
        if (pessoas >= n) break;
    }
    printf("%d\n", i);

    return 0;
}