#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
    scanf("%d", &n);
    int minimum = INT_MAX;
    int minIdx = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &m);
        int effort = 0;
        int effortReverse = 0;
        int lasth;
        scanf("%d", &lasth); 
        for (int j = 1; j < m; j++) {
            int h;
            scanf("%d", &h);
            effort += max(0, h-lasth);
            effortReverse += max(0, lasth-h);
            lasth = h;
        }
        int minEffort = min(effort,effortReverse);
        if (minEffort < minimum) {
            minimum = minEffort;
            minIdx = i;
        }
    }

    printf("%d\n", minIdx);

    return 0;
}

/*
5
4 498 500 498 498
10 60 60 70 70 70 70 80 90 90 100
5 200 190 180 170 160
2 1000 900
4 20 20 20 20

*/