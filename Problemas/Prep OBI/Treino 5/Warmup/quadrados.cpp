#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    scanf("%d", &n);
    int mat[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    int magicSum = -1;
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            sum += mat[i][j];
        }
        if (magicSum == -1) magicSum = sum;
        else if (sum != magicSum) {
            printf("-1\n");
            return 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            sum += mat[j][i];
        }
        if (sum != magicSum) {
            printf("-1\n");
            return 0;
        }
    }

    int sumDiag1 = 0, sumDiag2 = 0;
    for (int i = 0; i < n; ++i) {
        sumDiag1 += mat[i][i];
        sumDiag2 += mat[i][n-i-1];
    }

    if (sumDiag1 != magicSum || sumDiag2 != magicSum) {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", magicSum);

    return 0;
}