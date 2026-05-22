#include <bits/stdc++.h>
using namespace std;

int n;
int mar[101][101];

int main() {
    scanf("%d", &n);
    for (int k = 0; k < n; k++) {
        int xi, xf, yi, yf;
        scanf("%d %d %d %d", &xi, &xf, &yi, &yf);
        for (int j = xi; j < xf; j++) {
            for (int i = yi; i < yf; i++) {
                mar[i][j]++;
            }
        }
    }
    int area = 0;
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            if (mar[i][j] >= 1) area++;
        }
    }
    printf("%d\n", area);

    return 0;
}