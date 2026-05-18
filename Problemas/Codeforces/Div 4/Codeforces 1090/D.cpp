#include <bits/stdc++.h>
using namespace std;

int t, n;

int main() {
    scanf("%d", &t);
    for (int _t = 0; _t < t; ++_t) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            printf("%d ", 2*i);
        }
        printf("\n");
    }

    return 0;
}