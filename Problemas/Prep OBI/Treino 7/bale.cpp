// TLE
#include <bits/stdc++.h>
using namespace std;

int n;
int a[100001];

int main() {
    scanf("%d", &n);
    int total = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", a+i);
        for (int j = 0; j < i; j++) {
            if (a[j] > a[i]) total++;
        }
    }
    printf("%d\n", total);

    return 0;
}

/*

para cada ni, contagem de valores nj maiores que ni para j < i

*/