#include <bits/stdc++.h>
using namespace std;

int n, k;
int primo[40];

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; ++i) {
        scanf("%d", primo+i);
    }

    int total = 0;
    for (int i = 1; i <= n; ++i) {
        bool coprimo = true;
        for (int j = 0; j < k; ++j) {
            if (i%primo[j] == 0) {
                coprimo = false;
                break;
            }
        }
        if (coprimo) {
            printf("%d ", i);
            ++total;
        }
    }
    printf("%d\n",total);

    return 0;
}