/*
Guloso Alice: Botar o menor divisor sempre como z
Guloso Bob: 
*/

#include <bits/stdc++.h>
using namespace std;

#define MAX_Ai 1000001

int t, n;
bool crivo[MAX_Ai];

int main() {
    memset(crivo, true, sizeof crivo);
    
    for (int i = 2; i*i < MAX_Ai; ++i) {
        for (int k = i*i; k < MAX_Ai; k += i) {
            crivo[k] = false;
        }
    }

    scanf("%d", &t);
    for (int _t = 0; _t < t; ++_t) {
        scanf("%d", &n);
        int a[n];
        bool ordered = true;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            if (i != 0 && a[i-1] > a[i]) ordered = false;
        }
        if (ordered) {
            printf("Bob\n");
            continue;
        }
        
        int p[n];
        memset(p, 0, sizeof p);
        for (int i = 0; i < n; ++i) {
            int fatores = 0;
            int primeiro = -1;
            for (int j = 2; j < a[i]; ++j) {
                if (crivo[j] && a[i]%j==0) {
                    ++fatores;
                    // printf("%d é o %do fator de %d\n",j,fatores,a[i]);
                    if (primeiro == -1) {
                        primeiro = j;
                        p[i] = j;
                    }
                }
                if (fatores >= 2) {
                    // printf("Muitos fatores\n");
                    goto alice;
                }
            }
            if (primeiro == -1) {
                p[i] = a[i];
            }
        }

        for (int i = 0; i < n-1; ++i) {
            if (p[i] > p[i+1]) {
                // printf("Primos desordenados\n");
                goto alice;
            }
        }
        printf("Bob\n");
        continue;

        alice:
        printf("Alice\n");
    }

    return 0;
}

/*
10  9   8 7  6 5  4 3 2 1
25 33 222 7 23 5 22 3 2 1

1          8192 677
1 2222222222222 677

 6 5
23 5

 6 7
23 7

*/