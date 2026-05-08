#include <bits/stdc++.h>
using namespace std;

#define UPPER 100000

int n;
bool primo[UPPER];

int main() {
    memset(primo, true, sizeof primo);
    primo[0] = false;
    primo[1] = false;
    for (int i = 2; i*i < UPPER; i++) {
        if (!primo[i]) continue;
        for (int j = i*i; j < UPPER; j+=i) {
            primo[j] = false;
        }
    }

    for (int t = 1; scanf("%d", &n) > 0 && (n!=0); ++t) {
        if (!primo[n]) printf("Nada\n");
        else {
            int digitos = n;
            bool super = true;
            while (digitos >= 1) {
                int digito = digitos % 10;
                if (!primo[digito]) {
                    super = false;
                    break;
                }
                digitos /= 10;
            }
            printf(super ? "Super\n" : "Primo\n");
        }
    }

    return 0;
}