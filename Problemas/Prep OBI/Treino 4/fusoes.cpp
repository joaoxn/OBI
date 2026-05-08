#include <bits/stdc++.h>
using namespace std;

int n, k;
int bancos[100001];

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i <= n; i++) {
        bancos[i] = i;
    }

    for (int i = 0; i < k; i++) {
        char c;
        int b1, b2;
        scanf(" %c %d %d", &c, &b1, &b2);

        if (c == 'F')  {
            while (bancos[b1] != b1) {
                b1 = bancos[b1];
            }
            while (bancos[b2] != b2) {
                b2 = bancos[b2];
            }

            bancos[max(b1,b2)] = min(b1,b2);
        } else {
            while (bancos[b1] != b1) {
                b1 = bancos[b1];
            }
            while (bancos[b2] != b2) {
                b2 = bancos[b2];
            }
            printf(b1 == b2 ? "S\n" : "N\n");
        }
    }

    return 0;
}

/*

1 2 3 4 5 4 7 8 9

*/