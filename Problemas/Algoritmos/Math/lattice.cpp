#include <iostream>
using namespace std;

int c, n;
int mat[1001][1001];

int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, (x % y));
}

int main() {
    scanf("%d", &c);

    for (int i = 0; i <= 1000; i++)
        for (int j = 0; j <= 1000; j++)
            mat[i][j] = gcd(i,j);

    for (int t = 1; t <= c; t++) {
        scanf("%d", &n);
        int sol = 0;

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (mat[i][j] == 1) sol++;
            }
        }
        printf("%d %d %d\n", t, n, sol);
    }
}