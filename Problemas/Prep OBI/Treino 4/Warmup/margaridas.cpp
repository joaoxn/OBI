#include <bits/stdc++.h>
using namespace std;

int l, c, m, n;
int mat[1000][1000];
int prefSumH[1000][1001];
int prefSumV[1001][1000];

int main() {
    scanf("%d %d %d %d", &l, &c, &m, &n);
    
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &mat[i][j]);
            prefSumH[i][j+1] = prefSumH[i][j] + mat[i][j];
            prefSumV[i+1][j] = prefSumV[i][j] + mat[i][j];
        }
    }

    int max = INT_MIN;

    for (int i = 0; i < l-m+1; i++) {
        for (int j = 0; j < c-n+1; j++) {
            int sum = 0;
            if (m > n) {
                for (int k = j; k < j+n; k++)
                    sum += prefSumV[i+m][k]-prefSumV[i][k];
            } else {
                for (int k = i; k < i+m; k++)
                    sum += prefSumH[k][j+n]-prefSumH[k][j];
            }
            if (sum > max) {
                max = sum;
            }
        }
    }
    printf("%d\n", max);

    return 0;
}