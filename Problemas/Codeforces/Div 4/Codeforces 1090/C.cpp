#include <bits/stdc++.h>
using namespace std;

int t, n;

int main() {
    scanf("%d", &t);
    for (int _t = 0; _t < t; ++_t) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            int maxn = n*3-(n-i)*2;
            printf("%d %d %d ", i, maxn-1, maxn);
        }
        printf("\n");
    }

    return 0;
}