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

    int l=1, r=maxBread;
    int mid = (l+r)/2;
    int best = 0;
    while (l <= r) {
        int fatias = calc(mid);
        if (fatias >= n) l=mid+1;
        if (fatias < n) r=mid-1;

        mid = (l+r)/2;
    }

    // while (calc(mid) >= n) ++mid;
    // while (calc(mid) < n) --mid;

    printf("%d\n", mid);

    return 0;
}