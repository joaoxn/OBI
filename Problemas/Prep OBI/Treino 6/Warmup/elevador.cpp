#include <bits/stdc++.h>
using namespace std;

int n, c;

int main() {
    scanf("%d %d", &n, &c);
    int pessoas = 0;
    for (int i = 0; i < n; ++i) {
        int s, e;
        scanf("%d %d", &s, &e);
        pessoas += e-s;
        if (pessoas > c) {
            printf("S\n");
            return 0;
        }
    }
    printf("N\n");

    return 0;
}